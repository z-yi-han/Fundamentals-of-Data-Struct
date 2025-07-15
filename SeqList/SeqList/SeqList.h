#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef int SLDataType;
//��̬˳���
typedef struct SeqList
{
	SLDataType * arr;//��̬�����һ��Ԫ�ص�λ��
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}SL;
//˳����ʼ��
void SLInit(SL* ps);
//˳�������
void SLDestroy(SL* ps);
//˳����ӡ
void SLPrint(SL s);
//β��
void SLPushBack(SL* ps, SLDataType x);
//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);
//ͷɾ
void SLPopFront(SL* ps);
//ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* sl, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
//����
int SLFind(SL* ps, SLDataType x);