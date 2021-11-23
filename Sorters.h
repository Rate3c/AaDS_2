#pragma once
#include <iostream>
#include <ctime>

using namespace std;

// check the correct array order for bogo sort
int SortedArray(int* array, size_t size) {
	while (size-- > 0)
		if (array[size - 1] > array[size])
			return 0;
	return 1;
}

//1. Binary search the element in array
int BinarySearch(int* array, size_t size, int searchElement) {
	if (SortedArray(array, size) == 1) { // if array is sorted in ascending order
		int left = 0;
		int right = size - 1;
		bool IsFound = false;
		int middle;

		while ((left <= right) && (IsFound != true)) {
			middle = (left + right) / 2; // calculate the middle index

			if (array[middle] == searchElement) IsFound = true; // if moddle index is looking for element
			if (array[middle] > searchElement) right = middle - 1; // discard the useless part of array
			else left = middle + 1;
		}

		if (IsFound) return middle; // if looking for element is exist
		else
		{
			throw invalid_argument("There is not this element in array");
		}
	}
	else throw invalid_argument("The array is not sorted");
}

//2. Quick sort 
void QuickSort(int* array, int first, int last) {
	int middle;
	int left = first, right = last;
	middle = array[(left + right) / 2]; //  calculate the middle element
	do
	{
		while (array[left] < middle) left++;
		while (array[right] > middle) right--;
		if (left <= right) // swap the elements
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	} 
	// sort the sub-array
	while (left < right);
	if (first < right) QuickSort(array, first, right); 
	if (left < last) QuickSort(array, left, last);
}

//3. Insertion sort
void InsertionSort(int array[], size_t size)
{
	int i, j;
	int key; //the number to be compared
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		/* move elements that are
		greater than key to one position ahead
		of their current position */
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

// swap the array random elements for bogo sort
void BogoShuffle(int* array, size_t size) {
	for (int i = 0; i < size; ++i)
		swap(array[i], array[(rand() % size)]);
}

//5. Bogo sort
void BogoSort(int* array, size_t size) {
	while (!SortedArray(array, size)) // while array is not sorted
		BogoShuffle(array, size); // swap the array random elements
}

//6. Counting sort for char
void CountingSort(char* array, size_t size) {
	char char_array[256] = { 0 };
	for (int i = 0; i < size; ++i) {
		++char_array[array[i]]; // calculate the count of each char
	}

	int order = 0; // go through all char
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < char_array[i]; ++j) {
			array[order++] = i;
		}
	}
}
