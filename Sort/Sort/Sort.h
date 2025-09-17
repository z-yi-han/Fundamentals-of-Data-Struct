#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void PrintArray(int* a, int n);

// ��ʵ������
void InsertSort(int* a, int n);

void ShellSort(int* a, int n);

void HeapSort(int* a, int n);

// �ʺϽ�ѧ��ʵ����ûɶ��ֵ
void BubbleSort(int* a, int n);

void SelectSort(int* a, int n);

void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n);