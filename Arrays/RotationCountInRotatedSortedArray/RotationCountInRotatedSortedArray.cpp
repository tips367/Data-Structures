/* Consider an array of distinct numbers sorted in increasing order. 
The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after
rotating the initial array twice.

*/

#include <iostream>

int findRotationCount(int arr[], int n)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		if (arr[low] <= arr[high])
			return low;
		int mid = low + (high - low) / 2;
		int next = mid + 1;
		int prev = mid - 1;
		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if (arr[mid] <= arr[high])
			high = mid - 1;
		else if (arr[low] <= arr[mid])
			low = mid + 1;
	}
	return -1;
}

int main()
{
	//int arr[] = { 15, 18, 2, 3, 6, 12 };
	//int arr[] = { 7, 9, 11, 12, 5 };
	int arr[] = { 2,3,4,5,6,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << findRotationCount(arr, n);
	return 0;
}
