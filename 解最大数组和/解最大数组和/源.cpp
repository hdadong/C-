#include<iostream>
#include<vector>
using namespace std;
int Find_Max_Crossing_Subarray(int arr[], int low, int mid, int hight)
{
	const int infinite = -9999;
	int left_sum = infinite;
	int right_sum = infinite;

	int max_left = -1, max_right = -1;

	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	sum = 0;
	for (int j = mid + 1; j <= hight; j++)
	{
		sum += arr[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}

	}
	return(left_sum + right_sum);
}

int Find_Maximum_Subarray(int arr[], int low, int hight)
{
	if (hight == low)//只有一个元素
		return arr[low];
	else
	{
		int mid = (low + hight) / 2;
		int leftSum = Find_Maximum_Subarray(arr, low, mid);//继续分割
		int rightSum = Find_Maximum_Subarray(arr, mid + 1, hight);//继续分割
		int crossSum = Find_Max_Crossing_Subarray(arr, low, mid, hight);//求当前子数组的最大和

		if (leftSum >= rightSum && leftSum >= crossSum)
			return leftSum;
		else if (rightSum >= leftSum && rightSum >= crossSum)
			return rightSum;
		else
			return crossSum;
	}
}

void MaxSubArraySum_Greedy(int arr[], vector<int>&subarr, int len)
{
	if (len == 0)
		return;
	int nMax = INT_MIN;
	int low = 0, hight = 0;
	int cur = 0;//一个指针更新子数组的坐去加
	int nSum = 0;
	for (int i = 0; i < len; i++)
	{
		nSum += arr[i];
		if (nSum > nMax)
		{
			nMax = nSum;
			low = cur;
			hight = i;
		}
		if (nSum < 0)
		{
			cur += 1;
			nSum = 0;
		}
	}
	for (int i = low; i <= hight; i++)
		subarr.push_back(arr[i]);

}

int main()
{
	int arr[]{ 1, -2, 3, 10, -4, 7, 2, -5 };
	vector<int>arrr;
	cout << Find_Maximum_Subarray(arr, 0, sizeof(arr) / sizeof(int));
	MaxSubArraySum_Greedy(arr, arrr, sizeof(arr) / sizeof(int));
	for (auto &k : arrr)
	{
		cout << k << " ";
	}
	getchar();
	return 0;
}