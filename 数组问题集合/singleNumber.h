/************************************************************************/
/** 
* ��Ŀ��ֻ����һ�ε�����
* ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
* 
* ˵����
* ����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
* ʾ�� 1:
* ����: ����: [2,2,1]
* ���: 1
* 
* ʾ�� 3:
* ����: ����: [4,1,2,1,2]
* ���: 4
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	// ���ַ���ʱ�临�Ӷ���n��ƽ����leetcode�ύ�ᳬ��ʱ������
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
				// ѭ������Ϊ��ÿ�������Լ�λ�õ�Ԫ�ؽ��бȽϣ����������������д��for��
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

	// ������򣬶����Ƶ���ѧ�����
	// ���a��b����ֵ����ͬ���������Ϊ1�����a��b����ֵ��ͬ�������Ϊ0��
	// 1.�����ɣ�a ^ b ^ c <=> a ^ c ^ b
	// 2.�κ�����0���Ϊ�κ��� 0 ^ n => n
	// 3.��ͬ�������Ϊ0: n ^ n => 0
	// var a = [2,3,2,4,4]
	// 2 ^ 3 ^ 2 ^ 4 ^ 4�ȼ��� 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
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