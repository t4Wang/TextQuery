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
	QueryResult(string s, shared_ptr<set<line_no>> p
		, shared_ptr<vector<string>> a) :
		sought(s), lines(p), article(a) {}
private:
	string sought;
	shared_ptr<vector<string>> article;
	shared_ptr<set<line_no>> lines;
};
