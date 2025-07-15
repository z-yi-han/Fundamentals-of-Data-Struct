#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
//����˫����Ľṹ
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
} LTNode;
//������˫�����ṩ�ķ���
//��ʼ��
//void LTInit(LTNode** pphead);
LTNode* LTInit();
//��ӡ
void LTPrint(LTNode * phead);
//����
void LTPushBack(LTNode* phead, LTDataType x);//��һ��ָ�룬��Ϊ�ڱ�λ���޸�
void LTPushFront(LTNode* phead, LTDataType x);
//ɾ��
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);
//����
LTNode* LTFind(LTNode* phead, LTDataType x);
//ָ��λ��֮�����
void LTInsert(LTNode* pos, LTDataType x);
//ɾ��pos�ڵ�
void LTErase(LTNode* pos);
//����
void LTDestroy(LTNode* phead);