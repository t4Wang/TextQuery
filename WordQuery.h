#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "QueryBase.h"
#include <iostream>
#include <string>
using namespace std;

class WordQuery: public QueryBase {
	friend class Query;			// Query使用WordQuery构造函数
protected:
	WordQuery(const string &s): query_word(s) {}
	// 具体的类：WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const override
			{ return t.query(query_word); }
	string rep() const override { return query_word; }
	string query_word;			// 要查找的单词
};

#endif
