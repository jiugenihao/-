#pragma once
#include <vector>
#include <map>
#include <iostream>

#include "rotateArray.h"
#include "containsDuplicate.h"

int main()
{
	
	// ��������1��δ��ʼ��������
	vector<int> tst1;

	// ʾ��2
	int arr[] = {1,2,3,1};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// ʾ��3
	int arr3[] = {1,2,3,4};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// ʾ��4
	int arr4[] = {1,1,1,3,3,4,3,2,4,2};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	
	bool flag1 = Solution::containsDuplicate2(tst1);
	bool flag2 = Solution::containsDuplicate2(tst2);
	bool flag3 = Solution::containsDuplicate2(tst3);
	bool flag4 = Solution::containsDuplicate2(tst4);

	return 0;
}