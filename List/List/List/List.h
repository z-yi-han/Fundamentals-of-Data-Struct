#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
//定义双链表的结构
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
} LTNode;
//定义向双链表提供的方法
//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();
//打印
void LTPrint(LTNode * phead);
//插入
void LTPushBack(LTNode* phead, LTDataType x);//传一级指针，因为哨兵位不修改
void LTPushFront(LTNode* phead, LTDataType x);
//删除
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);
//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
//指定位置之后插入
void LTInsert(LTNode* pos, LTDataType x);
//删除pos节点
void LTErase(LTNode* pos);
//销毁
void LTDestroy(LTNode* phead);