#include <iostream>
#include <algorithm>
using namespace std;

// Partition using Lomuto partition scheme
int Partition(int a[], int start, int end)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[end];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = start;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);

	// return pIndex (index of pivot element)
	return pIndex;
}

// Quicksort routine
void QuickSort(int a[] ,int start, int end)
{
	// base condition
	if (start >= end)
		return;

	// rearrange the elements across pivot
	int pivot = Partition(a, start, end);

	// recur on sub-array containing elements that are less than pivot
	QuickSort(a, start, pivot - 1);

	// recur on sub-array containing elements that are more than pivot
	QuickSort(a, pivot + 1, end);
}

// Quicksort algorithm implementation in C++
int main()
{
	int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
	int n = sizeof(a)/sizeof(a[0]);

	QuickSort(a, 0, n - 1);

	// print the sorted array
	for (int i = 0 ; i < n; i++)
		cout << a[i] << " ";

	return 0;
}