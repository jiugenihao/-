/************************************************************************/
/** 
* ��Ŀ������֮��
* ����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
* ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
*
* ʾ�� 1:
* ���� nums = [2, 7, 11, 15], target = 9
* ��Ϊ nums[0] + nums[1] = 2 + 7 = 9
* ���Է��� [0, 1]
* ʾ�� 2:
* ���� nums = [3, 3], target = 6
* ��Ϊ nums[0] + nums[1] = 3 + 3 = 6
* ���Է��� [0, 1]
*
* ע�⣺
* ��ΪҪ�������������Բ������򣬲�Ҫ����˳��
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution 
{
	// �������
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> ret;
		if (nums.size() < 2)
		{
			return ret;
		}

		int len = nums.size();
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
					break;
				}
			}
		}
		return ret;
	}

	
	vector<int> twoSum2(vector<int>& nums, int target) 
	{
		vector<int> ret;
		if (nums.size() < 2)
		{
			return ret;
		}

		

		return ret;
	}
}