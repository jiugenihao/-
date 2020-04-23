/************************************************************************/
/** 
* ��Ŀ�������ظ�Ԫ��
* ����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

* �������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
* 
* ʾ�� 1:
* ����: [1,2,3,1]
* ���: true
* 
* ʾ�� 2:
* ����: [1,2,3,4]
* ���: false
* 
* ʾ�� 3:
* ����: [1,1,1,3,3,4,3,2,4,2]
* ���: true
*/
/************************************************************************/

#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	bool containsDuplicate(vector<int>& nums) 
	{
		int len = nums.size();
		if (len <= 1)
		{
			return false;
		}

		map<int, int> tmp;
		for (auto val : nums)
		{
			auto iter = tmp.find(val);
			if (iter != tmp.end())
			{
				return true;
			}
			else
			{
				tmp[val] = 1;
			}
		}
		
		return false;
	}

	bool containsDuplicate2(vector<int>& nums) 
	{
		int len = nums.size();
		if (len <= 1)
		{
			return false;
		}

		set<int> tmp;
		for (int i = 0; i < len; ++i)
		{
			if (tmp.find(nums[i]) != tmp.end())
			{
				return true;
			} 
			else
			{
				tmp.insert(nums[i]);
			}

		}

		return false;
	}
}
