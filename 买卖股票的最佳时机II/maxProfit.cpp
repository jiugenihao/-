/************************************************************************/
/** 
* ��Ŀ������
* ����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
* ���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
* ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
* 
* ʵ��1��
* ����: [7,1,5,3,6,4]
* ���: 7
* ����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 3 �죨��Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
* ����ڵ� 4 �죨��Ʊ�۸� = 3����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ������, ��ʽ������ܻ������ = 6-3 = 3 ��
* 
* ʾ��2��
* ����: [1,2,3,4,5]
* ���: 4
* ����: �ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
* ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�����������
* ��Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
*
* ʾ��3��
* ����: [7,6,4,3,1]
* ���: 0
* ����: �����������, û�н������, �����������Ϊ 0��

* ��ʾ��
* 1 <= prices.length <= 3 * 10 ^ 4
* 0 <= prices[i] <= 10 ^ 4
*/
/************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) 
{
	int len = prices.size();
	if (len < 1 || len > 30000)
	{
		return 0;
	}

	int profit = 0;
	int begin = 0;
	int end = 0;
	while (end < len - 1)
	{
		if (prices[end] > prices[end + 1])
		{
			int sub = prices[end] - prices[begin];
			profit += sub;

			begin = end + 1;
		}
		++end;
	}
	// end = len-1
	if (end == len - 1 && end > begin)
	{
		int sub = prices[end] - prices[begin];
		profit += sub;
	}

	return profit;
}

int main()
{
	int profit = 0;
	// ��������1��δ��ʼ��������
	vector<int> tst1;

	// ʾ��2
	int arr[] = {7,1,5,3,6,4};
	vector<int> tst2(arr, arr + sizeof(arr) / sizeof(int));

	// ʾ��3
	int arr3[] = {1,2,3,4,5};
	vector<int> tst3(arr3, arr3 + sizeof(arr3) / sizeof(int));

	// ʾ��4
	int arr4[] = {7,6,4,3,1};
	vector<int> tst4(arr4, arr4 + sizeof(arr4) / sizeof(int));

	profit = maxProfit(tst1);
	cout<<"ʾ��1: "<<profit<<endl;

	profit = maxProfit(tst2);
	cout<<"ʾ��2: "<<profit<<endl;

	profit = maxProfit(tst3);
	cout<<"ʾ��2: "<<profit<<endl;

	profit = maxProfit(tst4);
	cout<<"ʾ��2: "<<profit<<endl;

	return 0;
}