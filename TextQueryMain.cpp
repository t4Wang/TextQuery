#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>
using namespace std;

void runQueries(ifstream &infile);

int main() {
	ifstream in("Pride and Prejudice.txt");
	if (! in.is_open())  {
    	cout << "Error opening file"; exit (1);
	}
	runQueries(in);

	char c;
	cin >> c;

	return 0;
}

void runQueries(ifstream &infile) {
	// infile是一个ifstream, 指向我们要处理的文件
	TextQuery tq(infile);	// 保存文件并建立查询map
	// 与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while(true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		// 若遇到文件尾或用户输入了‘q’时循环终止
		if (!(cin >> s) || s == "q") break;
		// 指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}
