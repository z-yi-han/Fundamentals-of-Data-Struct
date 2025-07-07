#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef int SLDataType;
//动态顺序表
typedef struct SeqList
{
	SLDataType * arr;//动态数组第一个元素的位置
	int size;//有效数据个数
	int capacity;//空间大小
}SL;
//顺序表初始化
void SLInit(SL* ps);
//顺序表销毁
void SLDestroy(SL* ps);
//顺序表打印
void SLPrint(SL s);
//尾插
void SLPushBack(SL* ps, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//指定位置之前插入/删除数据
void SLInsert(SL* sl, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
//查找
int SLFind(SL* ps, SLDataType x);