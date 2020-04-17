/************************************************************************/
/** 
* 题目描述：
* 给定一个排序数组，你需要在 (原地) 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须在 (原地) 修改输入数组,并在使用 O(1) 额外空间的条件下完成。
* 
* 实例1：
* 给定数组 nums = [1,1,2], 
* 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
* 你不需要考虑数组中超出新长度后面的元素
* 
* 示例2：
* 给定 nums = [0,0,1,1,1,2,2,3,3,4],
* 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
* 你不需要考虑数组中超出新长度后面的元素。
*/
/************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	// 如果传入未初始化的数组，没有这个判断会报错
	if (nums.size() == 0)
	{
		return 0;
	}

	auto iter = nums.begin();
	++iter;	// 从第二个元素开始比较
	while (iter != nums.end())
	{
		if (*iter == *(iter - 1))
		{
			iter = nums.erase(iter);
		} 
		else
		{
			++iter;
		}
	}

	return nums.size();
}

int main()
{
	// 测试用例1：未初始化的数组
	vector<int> testVec;

	// 测试用例2：初始化的有序数组
	int arr[] = {0,0,1,1,1,2,2,3,3,4,55,56,56,56,57,111,121,131,131};
	vector<int> testVec2(arr, arr + sizeof(arr) / sizeof(int));
	
	// 执行测试
	int len = removeDuplicates(testVec2);
	for (int i = 0; i < len; i++) 
	{
		cout<<testVec2[i]<<" ";
	}
	return 0;
}