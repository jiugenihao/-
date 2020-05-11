#pragma once
#include "CommonHeaders.h"
#include "rotateArray.h"
#include "containsDuplicate.h"
#include "singleNumber.h"
#include "intersect.h"

int main()
{
	__int64 xxx = 0;
	cout<<sizeof(long long)<<endl;
	
	// 测试用例1：未初始化的数组
	vector<int> tst1;

	// 示例2
	int arr[] = {1,2,2,1};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// 示例3
	int arr3[] = {2,2};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// 示例4
	int arr4[] = {4,9,5};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	
	// 示例5
	int arr5[] = {9,4,9,8,4};
	vector<int> tst5(arr5, arr5 + sizeof(arr5) / sizeof(int));

	vector<int> ret1 = Solution::intersect(tst1, tst1);
	vector<int> ret2 = Solution::intersect(tst1, tst2);
	vector<int> ret3 = Solution::intersect(tst2, tst3);
	vector<int> ret4 = Solution::intersect(tst4, tst5);

	// sorted示例1
	int arr6[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	vector<int> tst6(arr6, arr6 + sizeof(arr6) / sizeof(int));

	// sorted示例2
	int arr7[] = {1,2,3,4};
	vector<int> tst7(arr7, arr7 + sizeof(arr7) / sizeof(int));

	vector<int> ret5 = Solution::intersect_sorted(tst6, tst7);

	return 0;
}