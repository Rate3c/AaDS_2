#include "Sorters.h"

int main() {
	const int size_array = 10;

	cout << "Generate an array with " << size_array << " elements:\n";
	int* QuickTest_array = new int[size_array];
	int first = 0; int last = size_array - 1;
	srand(time(NULL));
	for (int i = 0; i < size_array; i++)	//fill array with random elements
	{
		QuickTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	cout << "\nSort the array by QuickSort:\n";
	QuickSort(QuickTest_array, first, last);
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	delete[]QuickTest_array; //clear memory

	cout << endl << endl;

	cout << "Generate an array with " << size_array << " elements:\n";
	int* InsertionArray_array = new int[size_array];
	for (int i = 0; i < size_array; i++) //fill array with random elements
	{
		InsertionArray_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << InsertionArray_array[i] << ' ';
	}
	cout << "\nSort the array by InsertionSort:\n";
	InsertionSort(InsertionArray_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << InsertionArray_array[i] << ' ';
	}
	delete[]InsertionArray_array;

	cout << endl << endl;

	cout << "Generate an array with " << size_array << " elements:\n";
	int* BogoTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)	//fill array with random elements
	{
		BogoTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	cout << "\nSort the array by BogoSort:\n";
	BogoSort(BogoTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	delete[]BogoTest_array;

	cout << endl << endl;

	cout << "Generate an array with " << size_array << " elements:\n";
	char* CountingTest_array = new char[size_array];
	for (int i = 0; i < size_array; i++)	//fill array with random elements
	{
		CountingTest_array[i] = rand() % 255;
	}
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	cout << "\nSort the array by CountingSort:\n";
	CountingSort(CountingTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	delete[]CountingTest_array;

	cout << endl << endl;

	cout << "Generate an array with " << size_array << " elements:\n";
	int* BinarySearchTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BinarySearchTest_array[i] = 20 - i;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << " ";
	}
	cout << "\nSort the array by BubbleSort:\n";
	InsertionSort(BinarySearchTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << ' ';
	}

	cout << endl << "\nGet the index of '50':\n";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 50);
	}
	catch (const invalid_argument e) {
		cout << e.what();
	}
	cout << "\nGet the index of '11':\n";
	cout << "The index of '11' is ";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 11);
	}
	catch (const invalid_argument e) {
		cout << e.what();
	}

	delete[]BinarySearchTest_array;

	cout << "\n\nCompare QuickSort and InsertionSort:\n\n";

	//QuickSort example
	for (int degree = 1; degree < 7; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double spendedTime = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL));
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			QuickSort(array, first, last);
			clock_t end = clock();
			spendedTime += long double(end - begin) / CLOCKS_PER_SEC;
		}
		spendedTime /= 10;
		cout << "QuickSort of " << size << " element array took " << spendedTime << " seconds\n";
		delete[]array;
	}

	cout << endl;

	// InsertionSort example
	for (int degree = 1; degree < 6; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double spendedTime = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL));
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			InsertionSort(array, size);
			clock_t end = clock();
			spendedTime += long double(end - begin) / CLOCKS_PER_SEC;
		}
		spendedTime /= 10;
		cout << "InsertionSort of " << size << " element array took " << spendedTime << " seconds\n";
		delete[]array;
	}
	return 0;
}