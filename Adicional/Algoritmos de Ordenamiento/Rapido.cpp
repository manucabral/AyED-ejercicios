#include <iostream>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++)
		if (arr[j] < pivot)
			swap(&arr[i], &arr[j]);

	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void quickSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pi = partition(arr, start, end);
		quickSort(arr, start, pi - 1);
		quickSort(arr, pi + 1, end);
	}
}

int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5}, n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	return 0;
}
