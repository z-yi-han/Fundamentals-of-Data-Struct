#include"SList.h"
//申请新节点
SLTNode * SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SLTPrintf(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)//pcur不为空指针
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
void SLTPushBack(SLTNode ** pphead, SLTDataType x)
{
	assert(pphead);
	//空链表和非空链表
	SLTNode * newnode =SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else {
		//先找到尾节点
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//ptail指向的就是尾节点
		ptail->next = newnode;
	}
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//newnode * pphead
	newnode->next = *pphead;
	*pphead = newnode;
	//链表为空的时候也能行得通
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	//链表只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//链表有多个节点
	//找到尾结点和他的前一个节点
	else {
		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
void SLTPopFront(SLTNode ** pphead)
{
	assert(*pphead && pphead);
	//先存储下一个节点，然后free,然后在赋值
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
SLTNode * SLTFind(SLTNode* phead, SLTDataType x)//不影响指针，传一级指针即可
{
	SLTNode* pcur = phead;//保证phead不变，要不然只能用一次
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
			pcur=pcur->next;//更新指针
	}
	return NULL;
}
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode= SLTBuyNode(x);
	//若pos==*pphead，直接头插
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* prev = pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
void SLTInsertAfter(SLTNode* pos, SLTDataType x)//不需要头节点，因为直接pos进行改变就行了
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//两种方式的选择，先指向pso->next,在指向newnode
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//pos是头节点
	if (pos == *pphead)
	{
		//头删
		SLTPopFront(pphead);
	}
	else{
	SLTNode * prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev,pos,pos->next
	prev->next = pos->next;
	free(pos);
	pos = NULL;
	}
}
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next && pos->next->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
void SListDesTroy(SLTNode** pphead)//销毁，一个一个节点销毁
{
	assert(pphead && *pphead);
	SLTNode * pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}