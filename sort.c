#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 显示数组
void show(int* a, int a_size) {
	if (a_size > 0) {
		printf("Array = [");
		for (int i = 0; i < a_size; i++) {
			printf(" %d", a[i]);
		}
		printf("]\n");
	}
}
// 选择排序
void selectionSort(int* a, int a_size) {
	if (a_size > 0) {
		for (int i = 0; i < a_size; i++) {
			int minIndex = i;
			for (int j = i + 1; j < a_size; j++) {
				if (a[minIndex] > a[j]) {
					minIndex = j;
				}
			}
			int temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
	}
}

// 冒泡排序
void bubbleSort(int* a, int a_size) {
	if (a_size > 0) {
		for (int i = 0; i < a_size; i++) {
			for (int j = 0; j < a_size - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
}

// 插入排序
void insertionSort(int* a, int a_size) {
	if (a_size > 0) {
		for (int i = 1; i < a_size; i++) {
			int temp = a[i];
			int j;
			for (j = i - 1; temp < a[j]; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
	}
}

// 快速排序

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}
// void quickSort(int arr[], int start, int end)
void quickSort(int *arr, int start, int end)
{
	int arrBase, arrMiddle;

	int tempStart = start,
		tempEnd = end;

	//对于这种递归的函数，内部必须要有一个函数返回的条件
	if (tempStart >= tempEnd)
		return;

	//拷贝一个基准值作为后面比较的参数
	arrBase = arr[start];
	while (start < end)
	{
		while (start < end && arr[end] > arrBase)
			end--;
		if (start < end)
		{
			swap(&arr[start], &arr[end]);
			start++;
		}

		while (start < end && arr[start] < arrBase)
			start++;
		if (start < end)
		{
			swap(&arr[start], &arr[end]);
			end--;
		}
	}
	arr[start] = arrBase;
	arrMiddle = start;

	//分治方法进行递归
	quickSort(arr, tempStart, arrMiddle - 1);
	quickSort(arr, arrMiddle + 1, tempEnd);
}

void main11()
{
	int a[] = { 5,1,32,4,25,32,33,13,55,62,4 };
	int a_size;
	a_size = sizeof(a) / sizeof(a[0]);
	show(a, a_size);
	quickSort(a,0, a_size-1);
	show(a, a_size);
	printf("hellow world!\n");
	system("pause");
	return;
}
