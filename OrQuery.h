#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

class OrQuery:public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right):
			BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};

// 取并集
QueryResult
OrQuery::eval(const TextQuery& text) const {
	// 通过Query成员lhs和rhs进行的虚调用
	// 调用eval返回每个运算对象的QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	// 将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// 插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(), right.end());
	// 返回一个新的QueryResult， 它表示lhs和rhs的并集
	return QueryResult(rep(), ret_lines, left.get_file());
}
#endif
