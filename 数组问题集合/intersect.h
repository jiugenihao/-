/************************************************************************/
/** 
* 题目：两个数组的交集 II
* 给定两个数组，编写一个函数来计算它们的交集。
* 
* 示例 1:
* 输入: nums1 = [1,2,2,1], nums2 = [2,2]
* 输出: [2,2]
* 
* 示例 2:
* 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
* 输出: [4,9]
*
* 说明：
* 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
* 我们可以不考虑输出结果的顺序。
*
* 进阶:
* 如果给定的数组已经排好序呢？你将如何优化你的算法？
* 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
* 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/
/************************************************************************/
#pragma once

#include "CommonHeaders.h"

namespace Solution
{
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> ret;
		int cnt = 0;	// 计数器
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

	// nums1和nums2都有序
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