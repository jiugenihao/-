/************************************************************************/
/** 
* 题目：加一
* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
* 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
* 你可以假设除了整数 0 之外，这个整数不会以零开头
* 
* 示例 1:
* 输入: [1,2,3]
* 输出: [1,2,4]
* 解释: 输入数组表示数字 123。
* 
* 示例 2:
* 输入: [4,3,2,1]
* 输出: [4,3,2,2]
* 解释: 输入数组表示数字 4321。

* 思考：
* 只有所有位都是9才会加1进位，数组长度加1，其他情况长度都不变
* 1.加1<10 不进位 数组最后一位+1即可
* 2.加1==10 进位 这位数设置为0，前一位执行加1 如果没有前一位，需要扩一位 前一位为0 再执行+1操作
* 3.重复执行1,2
* 方法2：
* 遍历数组，计算总数，加1后再写回数组，比如[1,2,3] 1*100+2*10+3 = 123
* len = nums.size()
* nums[0] * pow(10, len-1 -0)
* nums[1] * pow(10, len-1 -1)
* nums[i] * pow(10, len-1 -i)
* 如果数组很长的话，会溢出
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution 
{
	// 这个方法通过修改sum的类型，可以计算int和long long等基础类型的值，但是无法达到题目要求
	// 题目的数组长度可能会很长，会超出int或者long long类型代表的最大值
	vector<int> plusOne(vector<int>& digits) 
	{
		vector<int> ret;
		int len = digits.size();
		if (len <= 0)
		{
			return ret;
		}

		bool all_9 = true;
		for (auto num : digits)
		{
			if (num != 9)
			{
				all_9 = false;
				break;
			}
		}

		if (all_9)
		{
			// 如果都是9，加1会进位，长度+1
			ret.push_back(1);
			for (int i = 0; i < len; ++i)
			{
				ret.push_back(0);
			}
		} 
		else
		{
			// int 最大为10位数，如果数组len大于10位就会越界
			int sum = 0;
			for (int i = 0; i < len; ++i)
			{
				sum += digits[i] * pow(10, len - 1 - i);
			}

			sum += 1;
			for (int j = 0; j < len; j++)
			{
				int val = sum / pow(10, len - 1 - j);	// 因为可能存在进位，所以从len开始
				sum = sum % (int)pow(10, len - 1 - j);
				ret.push_back(val);
			}
		}

		return ret;
	}

	vector<int> plusOne2(vector<int>& digits)
	{
		vector<int> ret;
		int len = digits.size();
		if (len <= 0)
		{
			return ret;
		}

		bool isCarry = true;	// 是否需要进位
		for (int i = len - 1; i >= 0; --i)
		{
			digits[i] += 1;
			if (digits[i] == 10)
			{
				digits[i] = 0;
				isCarry = true;
			}
			else
			{
				isCarry = false;
				break;
			}
		}

		if (isCarry)
		{
			ret.push_back(1);
			for (auto num : digits)
			{
				ret.push_back(num);
			}
		} 
		else
		{
			std::copy(digits.begin(), digits.end(), std::back_inserter(ret));
		}

		return ret;
	}
};