/************************************************************************/
/** 
* 题目：存在重复元素
* 给定一个整数数组，判断是否存在重复元素。

* 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
* 
* 示例 1:
* 输入: [1,2,3,1]
* 输出: true
* 
* 示例 2:
* 输入: [1,2,3,4]
* 输出: false
* 
* 示例 3:
* 输入: [1,1,1,3,3,4,3,2,4,2]
* 输出: true
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
