#ifndef QUERY_H
#define QUERY_H

class Query {
friend Query operator&(const Query&, const Query&);
friend Query operator|(const Query&, const Query&);
friend Query operator~(const Query&);
public:
	Query(const string &q = ""): key:(q) {}
private:
	QueryBase queryBase;
}

#endif
