#pragma once
#include "CommonHeaders.h"
#include "rotateArray.h"
#include "containsDuplicate.h"
#include "singleNumber.h"

int main()
{
	
	// 测试用例1：未初始化的数组
	vector<int> tst1;

	// 示例2
	int arr[] = {2,2,1};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// 示例3
	int arr3[] = {4,1,2,1,2};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// 示例4
	int arr4[] = {1,1,3,3,4,2,4,2,5,7,7};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	
	int num1 = Solution::singleNumber3(tst1);
	int num2 = Solution::singleNumber3(tst2);
	int num3 = Solution::singleNumber3(tst3);
	int num4 = Solution::singleNumber3(tst4);

	return 0;
}