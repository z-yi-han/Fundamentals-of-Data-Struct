#pragma once
#include"List.h"
//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	node->data = x;
	node->next = node;
	node->prev = node;
	return node;
}
//void LTInit(LTNode** pphead)
//{
//	//给双向链表创建一个哨兵位
//	*pphead = LTBuyNode(-1);
//}
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur=pcur->next;
	}
	printf("\n");
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newndoe phead->next
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	newnode->prev = phead;
	newnode->next = phead->next;
	phead->next->prev = newnode;//和下面的代码不能完全交换
	phead->next = newnode;
}
void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next!=phead);
	LTNode* del = phead->prev;
	//phead del->prev del
	del->prev->next = phead;
	phead->prev = del->prev;
	//删除del
	free(del);
	del = NULL;
} 
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	//phead del del->next
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		return NULL;
	}
}
void LTInsert(LTNode* pos, LTDataType x)
{
	LTNode* newnode = LTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
void LTErase(LTNode* pos)//为什么不传二级指针：保持接口一致性
{
	assert(pos);
	//pos->prev pos pos->next
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != pcur->next)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}