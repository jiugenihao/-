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
#include "rotate.h"

/************************************************************************/
/* 全局测试数据                                                                     */
/************************************************************************/
// 测试用例1：未初始化的数组
vector<int> tst1;

// 示例2
int arr[] = {2, 7, 11, 15};
vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

// 示例3
int arr3[] = {3,3};
vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

// 示例4
int arr4[] = {9,0,9};
vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));

// 示例5
int arr5[] = {9,0,9,0,0};
vector<int> tst5(arr5, arr5 + sizeof(arr5) / sizeof(int));

// sorted示例1
int arr6[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
vector<int> tst6(arr6, arr6 + sizeof(arr6) / sizeof(int));

// sorted示例2
int arr7[] = {1,2,3,4};
vector<int> tst7(arr7, arr7 + sizeof(arr7) / sizeof(int));

void testMoveZeros()
{
	Solution::moveZeroes(tst1);
	Solution::moveZeroes(tst5);
}

void testTwoSum()
{
	vector<int> ret1, ret2, ret3;
	ret1 = Solution::twoSum2(tst1, 9);
	ret2 = Solution::twoSum2(tst2, 9);
	ret3 = Solution::twoSum2(tst3, 6);
}

void testSudo()
{
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
}

void testRotateMatrix()
{
	vector<vector<int>> matrix3_v(3);
	vector<vector<int>> matrix4_v(4);
	int matrix3[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
	int matrix4[4][4] = { {5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16} };
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix3_v[i].push_back(matrix3[i][j]);
		}
	}
	Solution::rotateMatrix(matrix3_v);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix4_v[i].push_back(matrix4[i][j]);
		}
	}
	Solution::rotateMatrix(matrix4_v);
}

int main()
{
	
	testRotateMatrix();
	return 0;
}