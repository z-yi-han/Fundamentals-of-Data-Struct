#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义节点的结构
//数据+指向下一个节点的指针
typedef int SLTDataType;
//数据类型可以根据需要修改
typedef struct SListNode {
	SLTDataType data; //数据域
	struct SListNode * next; //指向下一个节点的指针
}SLTNode;
void SLTPrintf(SLTNode* phead);//打印函数
void SLTPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SLTPushFront(SLTNode** pphead, SLTDataType x);//头插
void SLTPopBack(SLTNode** pphead);//尾删
void SLTPopFront(SLTNode** pphead);//头删
SLTNode * SLTFind(SLTNode* phead, SLTDataType x);//查找
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在指定位置之前插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);//在指定位置之后插⼊数据
void SLTErase(SLTNode** pphead, SLTNode* pos);//删除pos节点
void SLTEraseAfter(SLTNode* pos);//删除pos之后的节点
void SListDesTroy(SLTNode** pphead);//销毁链表