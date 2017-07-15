#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

class QueryResult;	// 为了定义函数query的返回类型，这个定义是必须的

class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> article;
	map<string, shared_ptr<set<line_no>>> word_index;
};

#endif
