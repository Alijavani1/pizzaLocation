#pragma once
#include "pizza.h"


// Merge Sort

void merge(pizza arr[],  int p,  int q,  int r,int mabna) {

	int n1 = q - p + 1;
	int n2 = r - q;

	pizza* L = new pizza[n1];
	pizza* M = new pizza[n2];



	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];


	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	if (mabna==0)
	{
		while (i < n1 && j < n2) {
			if (L[i].get_x() <= M[j].get_x()) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = M[j];
				j++;
			}
			k++;
		}
	}
	else {
		while (i < n1 && j < n2) {
			if (L[i].get_y() <= M[j].get_y()) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = M[j];
				j++;
			}
			k++;
		}
	}
	

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}


pizza* mergeSort(pizza arr[],  int l,  int r,int mabna ) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m,mabna);
		mergeSort(arr, m + 1, r,mabna);

		merge(arr, l, m, r,mabna);
	}
	return arr;
}

pizza* mysort(pizza arr[],int arr_size,int mabna ) {
	return mergeSort(arr, 0, arr_size, mabna);
}

// Counting Sort

void countSort(pizza arr[], int len) {
	pizza output[100];
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i].get_numberLocal()>max)
		{
			max = arr[i].get_numberLocal();
		}
	}

	int* count = new int[max + 1]{ 0 };
	for (int i = 0; i < len; i++)
	{
		count[arr[i].get_numberLocal()] += 1;
	}
	
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = len - 1; i >= 0; i--) {
		output[count[arr[i].get_numberLocal()] - 1] = arr[i];
		count[arr[i].get_numberLocal()]--;
	}

	for (int i = 0; i < len; i++) {
		arr[i] = output[i];
	}
	
}


















































//pizza* merge(pizza array[], int const left, int const mid,
//	int const right, int m)
//{
//	int const subArrayOne = mid - left + 1;
//	int const subArrayTwo = right - mid;
//
//
//	auto* leftArray = new pizza[subArrayOne],
//		* rightArray = new pizza[subArrayTwo];
//
//
//	for (auto i = 0; i < subArrayOne; i++)
//		leftArray[i] = array[left + i];
//	for (auto j = 0; j < subArrayTwo; j++)
//		rightArray[j] = array[mid + 1 + j];
//
//	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
//	int indexOfMergedArray = left;
//
//	if (m == 0)
//	{
//		while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
//			if (leftArray[indexOfSubArrayOne].get_x() <= rightArray[indexOfSubArrayTwo].get_x()) {
//				array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//				indexOfSubArrayOne++;
//			}
//			else {
//				array[indexOfMergedArray]
//					= rightArray[indexOfSubArrayTwo];
//				indexOfSubArrayTwo++;
//			}
//			indexOfMergedArray++;
//		}
//	}
//	else {
//		while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
//			if (leftArray[indexOfSubArrayOne].get_y() <= rightArray[indexOfSubArrayTwo].get_y()) {
//				array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//				indexOfSubArrayOne++;
//			}
//			else {
//				array[indexOfMergedArray]
//					= rightArray[indexOfSubArrayTwo];
//				indexOfSubArrayTwo++;
//			}
//			indexOfMergedArray++;
//		}
//	}
//
//
//
//	while (indexOfSubArrayOne < subArrayOne) {
//		array[indexOfMergedArray]
//			= leftArray[indexOfSubArrayOne];
//		indexOfSubArrayOne++;
//		indexOfMergedArray++;
//	}
//
//
//	while (indexOfSubArrayTwo < subArrayTwo) {
//		array[indexOfMergedArray]
//			= rightArray[indexOfSubArrayTwo];
//		indexOfSubArrayTwo++;
//		indexOfMergedArray++;
//	}
//
//
//
//
//
//	delete[] leftArray;
//	delete[] rightArray;
//
//	return array;
//}
//
//
//pizza* mergeSort(pizza array[], int const begin, int const end, int m)
//{
//	if (begin >= end)
//		return array;
//
//	int mid = begin + (end - begin) / 2;
//	mergeSort(array, begin, mid, m);
//	mergeSort(array, mid + 1, end, m);
//	merge(array, begin, mid, end, m);
//}
//
//
//
//
//
//pizza* mysort(pizza arr[], int m,int arr_size) {
//	return mergeSort(arr, 0, arr_size, m);
//}
//

