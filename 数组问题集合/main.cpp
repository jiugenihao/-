#pragma once
#include "CommonHeaders.h"
#include "rotateArray.h"
#include "containsDuplicate.h"
#include "singleNumber.h"
#include "intersect.h"
#include "plusOne.h"
#include "moveZeroes.h"
#include "twoSum.h"

int main()
{
	__int64 xxx = 0;
	cout<<sizeof(long long)<<endl;
	
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

	vector<int> ret1, ret2, ret3;

	Solution::moveZeroes(tst1);
	ret1 = Solution::twoSum(tst1, 9);
	ret2 = Solution::twoSum(tst2, 9);
	ret3 = Solution::twoSum(tst3, 6);
	
	return 0;
}