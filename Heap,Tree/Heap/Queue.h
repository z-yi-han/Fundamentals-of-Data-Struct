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
	QNode* phead;//ͷָ��
	QNode* ptail;//βָ��
	int size;//����
} Queue;
void QueueInit(Queue* pq);//��ʼ��
void QueueDestroy(Queue* pq);//����
void QueuePush(Queue* pq,QDataType x);//����
void QueuePop(Queue* pq);//ɾ��
// ȡ��ͷ�Ͷ�β������
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);//��ȡ���г���
bool QueueEmpty(Queue* pq);//�п�