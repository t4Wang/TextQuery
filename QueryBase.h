#ifndef QUERYBASE_H
#define QUERYBASE_H

#include "Query.h"
#include "TextQuery.h"

class QueryBase {
friend class Query;
protected:
	using line_no = TextQuery::line_no;	// 用于eval函数
	virtual ~QueryBase() = default;
private:
	// eval 返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep 是表示查询的一个string
	virtual string rep() const = 0;
};

#endif
