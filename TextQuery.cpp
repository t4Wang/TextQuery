
#include "TextQuery.h"
#include "QueryResult.h"

// #include <cstddef>
#include <memory>  // 
#include <sstream>	// istringstream
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
// #include <cctype>
// #include <cstring>
// #include <utility>
using namespace std;

/*
 * 构造
 * 读取输入文件并建立单词到行号的映射
 */
TextQuery::TextQuery(ifstream &is): article(new vector<string>) {
	string text;

	while(getline(is, text)) {					// 读入一行文本
		article -> push_back(text);				// 存入vector
		int n = article -> size() - 1;				// 获取存入vector的当前行号
		istringstream line(text);				// 将这行文本分解为单词
		string word;
		while(line >> word) {					// 遍历当前行的单词
			auto &lines = word_index[word];		// 获取当前单词文本的出现行号集合
			// 若word不在map，下标运算符会把word添加到word_index map中，lines为空指针			
			if (!lines) 						// 行号集合不存在(map自动创建)
				lines.reset(new set<line_no>);	// 分配一个新set存储当前单词的行号
			lines -> insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const {
	// 如果未找到sought，我们将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// 使用find而不是下标运算符来查找单词，避免将单词添加到word_index中
	auto loc = word_index.find(sought);
	if (loc == word_index.end())
		return QueryResult(sought, nodata, article);
	else
		return QueryResult(sought, loc->second, article);
}

