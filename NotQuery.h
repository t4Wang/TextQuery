#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "QueryBase.h"

class NotQuery: public: QueryBase {
	friend Query operator~(const Query&);
	NotQuery(const Query &q): query(q) {}
	// 具体的类：NotQuery将定义所有继承而来的纯虚函数
	string rep() const override {return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const override;
	Query query;
};

#endif
