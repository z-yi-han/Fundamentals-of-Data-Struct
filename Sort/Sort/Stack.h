#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//ջ���±�
	int capacity;//�������ɶ�̬����
}ST;

// ��ʼ��������
void STInit(ST* pst);
void STDestroy(ST* pst);

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// ȡջ������
STDataType STTop(ST* pst);

// �п�
bool STEmpty(ST* pst);
// ��ȡ���ݸ���
int STSize(ST* pst);