#include <iostream>
#include <time.h>

using namespace std;

void Test();
void Sort(int* arr, int n, void(*f)(int*, int));
void SelectionSort(int* arr, int n);
void InsertionSort(int* arr, int n);
void BubbleSort(int* arr, int n);

int main()
{
	// 난수(랜덤)
	srand((unsigned int)time(NULL));

	// 함수 포인터 - 반환 값 (*변수명) (매개변수)
	void(*func)() = nullptr;

	func = Test;
	func();

	int arr[10] = {};

	for (int i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 100 + 1;
	}

	printf("정렬 전: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}

	Sort(arr, 10, InsertionSort);

	printf("정렬 후: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void Test()
{
	printf("Test()\n");
}

void Sort(int* arr, int n, void(*f)(int*, int))
{
	f(arr, n);
}

void SelectionSort(int* arr, int n)
{
	printf("\n선택 정렬 수행 중...\n");

	for (int i = 0; i < n - 1; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		swap(arr[i], arr[minIndex]);
	}
}

void InsertionSort(int* arr, int n)
{
	printf("\n삽입 정렬 수행 중...\n");

	for (int i = 1, j = 0; i < n; ++i)
	{
		int key = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > key; --j)
		{
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = key;
	}
}

void BubbleSort(int* arr, int n)
{
	printf("\n버블 정렬 수행 중...\n");

	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
