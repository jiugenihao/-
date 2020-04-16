/* 
 * File:   Permutation.cpp
 * Desc:   求一个字符串的全排列
 *
 * Author: jiuge2
 * Created:2020-04-16
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;

void Permutation(string str, string prefix)
{
	cout << "str = " << str << " pre = " << prefix << endl;
	if (str.length() == 0)
	{
		cout << prefix << endl;
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			string rem = str.substr(0, i) + str.substr(i + 1);
			Permutation(rem, prefix + str.at(i));
		}
	}
}
void Permutation(string str)
{
	Permutation(str, "");
}

// 去重版本
void Permutation(string str, string prefix, std::set<string>& str_set)
{
	if (str.length() == 0)
	{
		str_set.insert(prefix);
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			string rem = str.substr(0, i) + str.substr(i + 1);
			Permutation(rem, prefix + str.at(i), str_set);
		}
	}
}

void Permutation(string str, std::set<string>& str_set)
{
	Permutation(str, "", str_set);
	for (auto item : str_set)
	{
		cout << item << endl;
	}
}




int main()
{
	string test_str = "abcd";
	cout << "未去重版本：" << endl;
	Permutation(test_str);
	cout << "++++++++++++++++++++++++++++" << endl;

// 	cout << "去重版本" << endl;
// 	set<string> removeDuplicateSet;
// 	Permutation(test_str, removeDuplicateSet);
// 	cout << "去重后个数为：" << removeDuplicateSet.size() << endl;

	std::cout << "Hello World!\n";
}