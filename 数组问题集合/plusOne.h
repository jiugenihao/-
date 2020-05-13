/************************************************************************/
/** 
* ��Ŀ����һ
* ����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
* ���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
* ����Լ���������� 0 ֮�⣬��������������㿪ͷ
* 
* ʾ�� 1:
* ����: [1,2,3]
* ���: [1,2,4]
* ����: ���������ʾ���� 123��
* 
* ʾ�� 2:
* ����: [4,3,2,1]
* ���: [4,3,2,2]
* ����: ���������ʾ���� 4321��

* ˼����
* ֻ������λ����9�Ż��1��λ�����鳤�ȼ�1������������ȶ�����
* 1.��1<10 ����λ �������һλ+1����
* 2.��1==10 ��λ ��λ������Ϊ0��ǰһλִ�м�1 ���û��ǰһλ����Ҫ��һλ ǰһλΪ0 ��ִ��+1����
* 3.�ظ�ִ��1,2
* ����2��
* �������飬������������1����д�����飬����[1,2,3] 1*100+2*10+3 = 123
* len = nums.size()
* nums[0] * pow(10, len-1 -0)
* nums[1] * pow(10, len-1 -1)
* nums[i] * pow(10, len-1 -i)
* �������ܳ��Ļ��������
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution 
{
	// �������ͨ���޸�sum�����ͣ����Լ���int��long long�Ȼ������͵�ֵ�������޷��ﵽ��ĿҪ��
	// ��Ŀ�����鳤�ȿ��ܻ�ܳ����ᳬ��int����long long���ʹ�������ֵ
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
			// �������9����1���λ������+1
			ret.push_back(1);
			for (int i = 0; i < len; ++i)
			{
				ret.push_back(0);
			}
		} 
		else
		{
			// int ���Ϊ10λ�����������len����10λ�ͻ�Խ��
			int sum = 0;
			for (int i = 0; i < len; ++i)
			{
				sum += digits[i] * pow(10, len - 1 - i);
			}

			sum += 1;
			for (int j = 0; j < len; j++)
			{
				int val = sum / pow(10, len - 1 - j);	// ��Ϊ���ܴ��ڽ�λ�����Դ�len��ʼ
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

		bool isCarry = true;	// �Ƿ���Ҫ��λ
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