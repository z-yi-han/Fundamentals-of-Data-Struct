#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void PrintArray(int *a,int n);
void InsertSort(int* a, int n);//²åÈëÅÅĞò
void ShellSort(int* a, int n);//Ï£¶ûÅÅĞò
void HeapSort(int* a, int n);//¶ÑÅÅĞò
void BubbleSort(int* a, int n);//Ã°ÅİÅÅĞò
void QuickSort(int* a, int left, int right);//¿ìËÙÅÅĞò
void QuickSortNonr(int* a, int left, int right);//·Çµİ¹é¿ìËÙÅÅĞò
void SelectSort(int* a, int n);//Ñ¡ÔñÅÅĞò
void MergeSort(int *a,int n);//¹é²¢ÅÅĞò
void MergeSortNinr(int* a, int n);//·Çµİ¹é¹é²¢ÅÅĞò