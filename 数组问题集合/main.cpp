#pragma once
#include <vector>
#include <iostream>

#include "rotateArray.h"


int main()
{
	// ��������1��δ��ʼ��������
	vector<int> tst1;

	// ʾ��2
	int arr[] = {1,2,3,4,5,6,7};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// ʾ��3
	int arr3[] = {-1,-100,3,99};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// ʾ��4
	int arr4[] = {1,2};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));
	
	Solution::rotate(tst4, 3);
	for (auto val : tst4)
	{
		cout<<val<<" ";
	}
	cout<<endl;

	Solution::rotate(tst3, 6);
	for (auto val : tst3)
	{
		cout<<val<<" ";
	}
	cout<<endl;

	return 0;
}