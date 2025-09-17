#include"Sort.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	//【0，n-1】
	//假设【0，end】有序，把end+1插入0，end，使其仍然有序
	for (int i = 0; i < n - 1; i++)
	{
		//单趟
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	//gap大于1的时候是预排序，gap等于1的时候是插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void AdjustDown(int* a, int n, int parent)
{
	// 先假设左孩子小
	int child = parent * 2 + 1;

	while (child < n)  // child >= n说明孩子不存在，调整到叶子了
	{
		// 找出小的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// 向下调整建堆 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin+1; i<=end ;++i)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		// 单趟
		int flag = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}
int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	//left midi right
	//if (a[left] < a[midi])
	//{
	//	if (a[midi] < a[right]) return midi;//left<midi<right
	//	else
	//		if (a[right]>a[left])//midi>right,midi>left
	//	{
	//		return right;
	//	}
	//	else {
	//		return left;
	//	}
	//}
	//else {//left>midi
	//	if (a[midi] > a[right]) return midi;
	//	else//left>midi right>midi
	//		if (a[left] > a[right])
	//			return right;
	//		else
	//			return left;
	//}
	if (a[left] > a[midi]) Swap(&a[left], &a[midi]);
	if (a[left] > a[right]) Swap(&a[left], &a[right]);
	if (a[midi] > a[right]) Swap(&a[midi], &a[right]);
	return midi; // 此时 a[mid] 一定是中位数
}
// hoare
int PartSort1(int* a, int left, int right)
{
	// 小区间优化，不再递归分割排序，减少递归的次数
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else {
		// 三数取中
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);

		int keyi = left;
		int begin = left, end = right;
		while (begin < end)
		{
			// 右边找小
			while (begin < end && a[end] >= a[keyi])
			{
				--end;
			}

			// 左边找大
			while (begin < end && a[begin] <= a[keyi])
			{
				++begin;
			}

			Swap(&a[begin], &a[end]);
		}
		Swap(&a[keyi], &a[begin]);
		return begin;
	}
}
//挖坑
int PartSort2(int* a, int left, int right)
{
	// 小区间优化
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		// 三数取中
		int midi = GetMidi(a, left, right);
		Swap(&a[left], &a[midi]);

		// 挖坑，保存基准值
		int pivot = a[left];
		int begin = left;
		int end = right;

		while (begin < end)
		{
			// 从右往左找小于 pivot 的数
			while (begin < end && a[end] >= pivot)
			{
				--end;
			}
			if (begin < end)
			{
				a[begin] = a[end]; // 把小的填到左边的坑
				++begin;
			}

			// 从左往右找大于 pivot 的数
			while (begin < end && a[begin] <= pivot)
			{
				++begin;
			}
			if (begin < end)
			{
				a[end] = a[begin]; // 把大的填到右边的坑
				--end;
			}
		}

		// 最后把 pivot 填回去
		a[begin] = pivot;
		return begin;
	}
}
//前后指针法
int PartSort3(int* a, int left, int right)
{
	// 小区间优化
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = left;
	//单趟
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int left, int right)
	{
		if (left >= right)
			return;

		int keyi = PartSort1(a, left, right);
		//int keyi = PartSort2(a, left, right);
		// int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
#include"Stack.h"
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi = PartSort3(a, begin, end);
		//[begin,key-1]  keyi [keti+1,right]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
		if (begin < keyi - 1)
		{
			STPush(&st,keyi-1);
			STPush(&st,begin);
		}
	}
	STDestroy(&st);
}
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	// 如果[begin, mid][mid+1, end]有序就可以进行归并了
	//分治
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	//开始归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++]; 
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//没用完
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	// gap每组归并数据的数据个数
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [begin1, end1][begin2, end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);

			// 第二组都越界不存在，这一组就不需要归并
			if (begin2 >= n)
				break;

			// 第二的组begin2没越界，end2越界了，需要修正一下，继续归并
			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		printf("\n");

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}
// 时间复杂度:O(N+range)
// 只适合整数/适合范围集中
// 空间范围度：O(range)
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	//printf("%d\n", range);

	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fail");
		return;
	}

	// 统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	// 排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(count);
}