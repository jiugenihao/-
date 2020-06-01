/************************************************************************/
/** 
* 题目：旋转图像
* 给定一个 n × n 的二维矩阵表示一个图像。
* 将图像顺时针旋转 90 度。
* 
* 说明：
* 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
* 
* 示例 1:
* 给定 matrix = 
* [
*  [1,2,3],
*  [4,5,6],
*  [7,8,9]
* ],
* 
* 原地旋转输入矩阵，使其变为:
* [
*  [7,4,1],
*  [8,5,2],
*  [9,6,3]
* ]
** 
* 示例 2:
* 给定 matrix =
* [
*  [ 5, 1, 9,11],
*  [ 2, 4, 8,10],
*  [13, 3, 6, 7],
*  [15,14,12,16]
* ], 
* 
* 原地旋转输入矩阵，使其变为:
* [
*  [15,13, 2, 5],
*  [14, 3, 4, 1],
*  [12, 6, 8, 9],
*  [16, 7,10,11]
* ]
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	// 利用辅助矩阵
	void rotateMatrix_1(vector<vector<int>>& matrix) 
	{
		int len = matrix.size();
		if (len < 1)
		{
			return;
		}

		for (auto row : matrix)
		{
			if (len != row.size())
			{
				return;
			}
		}

		vector<vector<int>> tmp(len, vector<int>(len));
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				tmp[j][len-1-i] = matrix[i][j];
			}
		}

		copy(tmp.begin(), tmp.end(), matrix.begin());
	}
	/************************************************************************/
	/**
	* 解题思路
	* 设i,j为原矩阵的横纵坐标，某一点坐标为(i,j)，通过示例，发现以下规律
	* 示例一：1(0,0) 2(0,1) 3(0,2) 旋转后变为 1(0,2) 2(1,2) 3(2,2)
	* 原坐标(i,j) 旋转后变为了(j, len-1-i)
	* 示例二 8(1,2)，按上面公式旋转后为(2,2),检验结果正确
	* 
	* 将矩阵分成4个相等的三角形，只要解开一个三角形，其他的跟随转就可以了，就是循环4次
	* 3*3:(0,0)(0,1)(1,1) 顶部三角
	* 4*4:(0,0)(0,1)(0,2)(1,3)
	*/
	void rotateMatrix(vector<vector<int>>& matrix) 
	{
		int len = matrix.size();
		if (len < 1)
		{
			return;
		}

		for (auto row : matrix)
		{
			if (len != row.size())
			{
				return;
			}
		}

		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i; j < len - 1 - i; ++j)	// j的范围是重点
			{
				int x1 = i;
				int y1 = j;
				int v1 = matrix[x1][y1];
				for (int k = 0; k < 4; ++k)
				{
					int x2 = y1;
					int y2 = len - 1 - x1;

					int tmpV = matrix[x2][y2];
					matrix[x2][y2] = v1;

					x1 = x2;
					y1 = y2;
					v1 = tmpV;
				}
			}
		}
	}
	
}
