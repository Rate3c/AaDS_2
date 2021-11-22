#include "pch.h"
#include "CppUnitTest.h"
#include "../AaDS_2/Sorters.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(QuickSortTest)
		{
			const int test_size = 100;
			int* test_array = new int[test_size];
			int first = 0; int last = test_size - 1;
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 100 - i;
			}
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsFalse(test_array[i] <= test_array[i + 1]);
			}
			QuickSort(test_array, first, last);
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsTrue(test_array[i] <= test_array[i + 1]);
			}
			delete[]test_array;
		}
		TEST_METHOD(InsertionSortTest)
		{
			const int test_size = 100;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 100 - i;
			}
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsFalse(test_array[i] <= test_array[i + 1]);
			}
			InsertionSort(test_array, test_size);
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsTrue(test_array[i] <= test_array[i + 1]);
			}
			delete[]test_array;
		}
		TEST_METHOD(BogoSortTest)
		{
			const int test_size = 10;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 10 - i;
			}
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsFalse(test_array[i] <= test_array[i + 1]);
			}
			BogoSort(test_array, test_size);
			for (int i = 0; i < test_size - 1; i++) {
				Assert::IsTrue(test_array[i] <= test_array[i + 1]);
			}
			delete[]test_array;
		}
		TEST_METHOD(SortedArrayTest)
		{
			const int test_size = 100;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 100 - i;
			}
			Assert::IsFalse(SortedArray(test_array, test_size));
			BogoSort(test_array, test_size);
			Assert::IsTrue(SortedArray(test_array, test_size));
			delete[]test_array;
		}
		TEST_METHOD(BogoShuffleTest)
		{
			const int test_size = 10;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 10 - i;
			}
			Assert::IsFalse(SortedArray(test_array, test_size));
			BogoSort(test_array, test_size);
			Assert::IsTrue(SortedArray(test_array, test_size));
			BogoShuffle(test_array, test_size);
			Assert::IsFalse(SortedArray(test_array, test_size));
			delete[]test_array;
		}
		TEST_METHOD(CountingSortTest)
		{
			const int test_size = 4;
			char* test_array = new char[test_size];
			test_array[0] = 'd';
			test_array[1] = 'c';
			test_array[2] = 'b';
			test_array[3] = 'a';
			Assert::IsTrue(test_array[0] == 'd');
			Assert::IsTrue(test_array[1] == 'c');
			Assert::IsTrue(test_array[2] == 'b');
			Assert::IsTrue(test_array[3] == 'a');

			CountingSort(test_array, test_size);

			Assert::IsTrue(test_array[0] == 'a');
			Assert::IsTrue(test_array[1] == 'b');
			Assert::IsTrue(test_array[2] == 'c');
			Assert::IsTrue(test_array[3] == 'd');

			delete[]test_array;
		}
		TEST_METHOD(BinarySearchTest)
		{
			const int test_size = 100;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 200 - i;
			}

			InsertionSort(test_array, test_size);
			try {
				BinarySearch(test_array, test_size, 455);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is not this element in array", error.what());
			}

			try {
				BinarySearch(test_array, test_size, 25);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is not this element in array", error.what());
			}
			Assert::IsTrue(BinarySearch(test_array, test_size, 199) == 98);
			delete[]test_array;
		}

	};
}