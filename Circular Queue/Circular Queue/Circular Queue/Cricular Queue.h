#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct//ѭ�����нṹ������
{
	int* a;
	int head;
	int tail;
	int k;
}MyCircularQueue;
MyCircularQueue * myCircularQueueCreate(int k);//����һ������Ϊl��ѭ�����У����ض���ָ��
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);//����в���һ��Ԫ�� value���ɹ����� true�����򷵻� false
bool myCircularQueueDeQueue(MyCircularQueue* obj);//�Ӷ���ɾ��һ��Ԫ�أ��ɹ����� true�����򷵻� false
int myCircularQueueFront(MyCircularQueue* obj);//���ض���Ԫ��
int myCircularQueueRear(MyCircularQueue* obj);//���ض�βԪ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj);//����Ƿ�Ϊ��
bool myCircularQueueIsFull(MyCircularQueue* obj);//����Ƿ�����
void myCircularQueueFree(MyCircularQueue* obj);//�ͷŶ���ռ�õ��ڴ�