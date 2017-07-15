#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"

class BinaryQuery: public QueryBase {
protected:
	BinaryQuery(const Query &l, const Query &r, string s):
			lhs(l), rhs(r), opSym(s) {}
	// 抽象类：BinaryQuery不定义eval
	string rep() const { return "(" + lhs.rep() 
			+ " " + opSym 
			+ " " + rhs.rep() + ")"; }
	Query lhs, rhs;			// 左侧运算和右侧运算对象
	string opSym;
};

#endif