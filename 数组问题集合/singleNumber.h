/************************************************************************/
/** 
* 题目：只出现一次的数字
* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
* 
* 说明：
* 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
* 示例 1:
* 输入: 输入: [2,2,1]
* 输出: 1
* 
* 示例 3:
* 输入: 输入: [4,1,2,1,2]
* 输出: 4
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	// 这种方法时间复杂度是n的平方，leetcode提交会超出时间限制
	int singleNumber(vector<int>& nums) 
	{
		if (nums.size() <= 0)
		{
			return -1;
		}

		for (int i = 0; i < nums.size() ; ++i)
		{
			bool isOnly = true;
			for (int j = 0; j < nums.size(); ++j)
			{
				// 循环条件为跟每个不是自己位置的元素进行比较，另外这个条件不能写到for中
				if (i == j)
				{
					continue;
				}
				if (nums[i] == nums[j])
				{
					isOnly = false;
					break;
				}
			}
			if (isOnly)
			{
				return nums[i];
			}
		}

		return -1;
	}

	// 利用异或，二进制的数学运算符
	// 如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。
	// 1.交换律：a ^ b ^ c <=> a ^ c ^ b
	// 2.任何数于0异或为任何数 0 ^ n => n
	// 3.相同的数异或为0: n ^ n => 0
	// var a = [2,3,2,4,4]
	// 2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
	int singleNumber2(vector<int>& nums) 
	{
		if (nums.size() <= 0)
		{
			return -1;
		}

		for (int i = 1; i < nums.size(); ++i)
		{
			nums[0] ^= nums[i];
		}
		return nums[0];
	}

	int singleNumber3(vector<int>& nums)
	{
		if (nums.size() <= 0)
		{
			return -1;
		}

		set<int> tmp;
		for (auto item : nums)
		{
			auto iter = tmp.find(item);
			if (iter == tmp.end())
			{
				tmp.insert(item);
			} 
			else
			{
				tmp.erase(iter);
			}
		}

		for (auto num : tmp)
		{
			return num;
		}
	}
}