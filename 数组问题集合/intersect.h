/************************************************************************/
/** 
* ��Ŀ����������Ľ��� II
* �����������飬��дһ���������������ǵĽ�����
* 
* ʾ�� 1:
* ����: nums1 = [1,2,2,1], nums2 = [2,2]
* ���: [2,2]
* 
* ʾ�� 2:
* ����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
* ���: [4,9]
*
* ˵����
* ��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
* ���ǿ��Բ�������������˳��
*
* ����:
* ��������������Ѿ��ź����أ��㽫����Ż�����㷨��
* ��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
* ��� nums2 ��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> ret;
		int cnt = 0;	// ������
		if (!nums1.empty() && !nums2.empty())
		{
			auto iter1 = nums1.begin();
			while (iter1 != nums1.end())
			{
				auto iter2 = nums2.begin();
				while (iter2 != nums2.end())
				{
					if (*iter1 == *iter2)
					{
						ret.push_back(*iter1);
						iter2 = nums2.erase(iter2);
						break;
					}
					else
					{
						++iter2;
					}
					++cnt;
				}
				++iter1;
				++cnt;
			}
		}

		cout<<"intersect count = "<<cnt<<endl;
		return ret;
	}

	// nums1��nums2������
	vector<int> intersect_sorted(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> ret;
		int cnt = 0;
		if (nums1.empty() || nums2.empty())
		{
			return ret;
		}

		if (nums1[0] > nums2[nums2.size() - 1] || nums2[0] > nums1[nums1.size() - 1])
		{
			return ret;
		}
		int i = 0, j = 0; 
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] < nums2[j])
			{
				++i;
			} 
			else if (nums1[i] > nums2[j])
			{
				++j;
			} 
			else
			{
				ret.push_back(nums1[i]);
				++i;
				++j;
			}
			++cnt;
		}

		cout<<"intersect_sorted count = "<<cnt<<endl;
		return ret;
	}
}