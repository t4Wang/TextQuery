#include "TextQuery.h"
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <memory>
using namespace std;

class QueryResult {

friend ostream& print(ostream&, const QueryResult&);
public:
	using line_no = vector<string>::size_type;
	// 查询字符串，输入行号，文本
	QueryResult(string s, shared_ptr<set<line_no>> p
		, shared_ptr<vector<string>> a):
		sought(s), lines(p), article(a) {}
	vector<string>* get_file() { return article; }
	auto begin() -> decltype(lines.begin()) { return lines.begin(); }
	auto end() -> decltype(lines.end()) { return lines.end(); }
private:
	string sought;
	shared_ptr<vector<string>> article;
	shared_ptr<set<line_no>> lines;
};
