/* 
 * File:   Permutation.cpp
 * Desc:   ��һ���ַ�����ȫ����
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

// ȥ�ذ汾
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
	cout << "δȥ�ذ汾��" << endl;
	Permutation(test_str);
	cout << "++++++++++++++++++++++++++++" << endl;

// 	cout << "ȥ�ذ汾" << endl;
// 	set<string> removeDuplicateSet;
// 	Permutation(test_str, removeDuplicateSet);
// 	cout << "ȥ�غ����Ϊ��" << removeDuplicateSet.size() << endl;

	std::cout << "Hello World!\n";
}