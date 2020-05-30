#pragma once
#include "CommonHeaders.h"
#include "rotateArray.h"
#include "containsDuplicate.h"
#include "singleNumber.h"
#include "intersect.h"
#include "plusOne.h"
#include "moveZeroes.h"
#include "twoSum.h"
#include "isValidSudoku.h"

int main()
{
	/*map<int, int> m_unit;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int key = i / 3 * 10 + j / 3;
			if (m_unit.find(key) != m_unit.end())
			{
				m_unit[key] += 1;
			} 
			else
			{
				m_unit[key] = 1;
			}
		}
	}

	cout<<m_unit.size()<<endl;*/

	/*char a[] = 'aaa',b[]='aaa';
	string A = 'AAA', B = 'AAA';
	cout << '*a��*b��ֵ�ֱ��ǣ�' << &a << '��' << &b << endl;
	cout << '*a��*b��ֵ�ֱ��ǣ�' << &(*a) << '��' << &(*b) << endl;
	cout << '*��aaa����ֵ�ǣ�'<< &'aaa' << endl;
	cout << '���� == �Ƚ�a,b�����ַ���������ǣ����Ϊ1������Ϊ0����'			<< (a == b ? 1 : 0)				<< endl;
	cout << '����strcmp()�Ƚ�a��b�����ַ���������ǣ����Ϊ0�����ȷ�0����'	<< (strcmp(a, b) == 0 ? 1 : 0)	<< endl;
	cout << '���� == �Ƚ�A,B����string������ǣ����Ϊ1������Ϊ0����'		<< (A == B ? 1 : 0)				<< endl;
	cout << '����compare()�Ƚ�A,B����string������ǣ����Ϊ0�����ȷ�0����'	<< (A.compare(B) == 0 ? 1 : 0)	<< endl;*/
	//int x = 10;
	//void* p = &x;
	//cout << sizeof(void*) << ' address' << p << endl;

	int autoarr[] = {1,2,3,4};
	for (auto id : autoarr)
	{
		cout<<id<<endl;
	}
	__int64 xxx = 0;
	cout<<sizeof(long long)<<endl;
	
	// ��������1��δ��ʼ��������
	vector<int> tst1;

	// ʾ��2
	int arr[] = {2, 7, 11, 15};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// ʾ��3
	int arr3[] = {3,3};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// ʾ��4
	int arr4[] = {9,0,9};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	
	// ʾ��5
	int arr5[] = {9,0,9,0,0};
	vector<int> tst5(arr5, arr5 + sizeof(arr5) / sizeof(int));

	// sortedʾ��1
	int arr6[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	vector<int> tst6(arr6, arr6 + sizeof(arr6) / sizeof(int));

	// sortedʾ��2
	int arr7[] = {1,2,3,4};
	vector<int> tst7(arr7, arr7 + sizeof(arr7) / sizeof(int));

	vector<int> ret1, ret2, ret3;

	Solution::moveZeroes(tst1);
	ret1 = Solution::twoSum2(tst1, 9);
	ret2 = Solution::twoSum2(tst2, 9);
	ret3 = Solution::twoSum2(tst3, 6);

	char sudo1[9][9] = { 
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	char sudo2[9][9] = { 
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	vector<vector<char>> sudo1_v(9);
	vector<vector<char>> sudo2_v(9);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			sudo1_v[i].push_back(sudo1[i][j]);
			sudo2_v[i].push_back(sudo2[i][j]);
		}
	}
	
	bool isSudo = Solution::isValidSudoku(sudo1_v);
	isSudo = Solution::isValidSudoku(sudo2_v);
	return 0;
}