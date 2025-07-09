#include"OJ.h"
//移除元素
//双指针法：创建两个变量src，dst
int removeElement(int* nums, int numsSize, int val) {
	//先创建两个变量
	int src, dst;
	src = dst = 0;
	while (src < numsSize)
	{
		if(nums[src]==val)
		{
			src++;
		}
		else {
			nums[dst] = nums[src];
			src++;
			dst++;
		}
	}
	return dst;
}
//合并两个有序数组
//思路1：冒泡排序：从后往前遍历，比较两个数组的元素大小，将较大的元素放到nums1的末尾，效率低下，影响整体运行效率
//思路2：从后往前比大小，比谁大，谁大往后放
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//nums1Size和nums2Size用不上
	int l1 = m - 1; //nums1的最后一个元素下标
	int l2 = n - 1; //nums2的最后一个元素下标
	int l3 = m + n - 1; //合并后数组的最后一个元素下标
	while (l1 >= 0 && l2 >= 0)//主要有一个为假就跳出循环
	{
		if (nums1[l1] < nums2[l2])
		{
			nums1[l3--] = nums2[l2--];
		}
		else {
			nums1[l3--] = nums1[l1--];

		}
	}
	//出了循环有两种情况：l1>=0或者l2>=0
	//实际上只需要处理一种情况，那就是l2>=0,说明l2中数据没有完全放到l1中
	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}
}