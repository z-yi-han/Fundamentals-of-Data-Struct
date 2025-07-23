#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct//循环队列结构体类型
{
	int* a;
	int head;
	int tail;
	int k;
}MyCircularQueue;
MyCircularQueue * myCircularQueueCreate(int k);//创建一个长度为l的循环队列，返回队列指针
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);//向队列插入一个元素 value，成功返回 true，否则返回 false
bool myCircularQueueDeQueue(MyCircularQueue* obj);//从队列删除一个元素，成功返回 true，否则返回 false
int myCircularQueueFront(MyCircularQueue* obj);//返回队首元素
int myCircularQueueRear(MyCircularQueue* obj);//返回队尾元素
bool myCircularQueueIsEmpty(MyCircularQueue* obj);//检查是否为空
bool myCircularQueueIsFull(MyCircularQueue* obj);//检查是否已满
void myCircularQueueFree(MyCircularQueue* obj);//释放队列占用的内存