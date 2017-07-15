#ifndef QUERY_H
#define QUERY_H

#include "QueryResult.h"
#include "TextQuery.h"
#include "NotQuery.h"
#include "WordQuery.h"
#include "QueryBase.h"
#include <iostream>
#include <string>
using namespace std;

class Query {
	// 这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator~(const Query&);
public:
	Query(const string &s): q(new WordQuery(s)) {}
	// 接口函数：调用对应的QueryBase操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	string rep() const { return q->rep(); }
private:
	Query(shared_ptr<QueryBase> query): q(query) {}
	shared_ptr<QueryBase> q;
}

ostream&
operator<<(ostream &os, const Query &query) {
	// Query::rep通过它的QueryBase指针对rep()进行了虚调用
	reutrn os << query.rep();
}

inline Query
operator~(const Query &operand) {
	return shared_ptr<QueryBase>(new NotQuery(operand));
}

#endif
