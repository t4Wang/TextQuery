#include "QueryResult.h"

#include <memory>
#include <string>
#include <iostream>
using namespace std;

ostream &print(ostream &os, const QueryResult &qr) {
	// 如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines->size() << "#" << endl;

	// 打印单词出现的每一行
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " 	// 行号 + 1
			<< *(qr.article->begin() + num) << endl;

	return os;
}
