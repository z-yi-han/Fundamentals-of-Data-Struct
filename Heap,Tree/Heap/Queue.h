#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
//typedef int QDataType;
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
} QNode;
typedef struct Queue
{
	QNode* phead;//头指针
	QNode* ptail;//尾指针
	int size;//长度
} Queue;
void QueueInit(Queue* pq);//初始化
void QueueDestroy(Queue* pq);//销毁
void QueuePush(Queue* pq,QDataType x);//插入
void QueuePop(Queue* pq);//删除
// 取队头和队尾的数据
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);//获取队列长度
bool QueueEmpty(Queue* pq);//判空