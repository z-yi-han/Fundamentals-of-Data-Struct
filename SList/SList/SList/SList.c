#include"SList.h"
//�����½ڵ�
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
	while (pcur)//pcur��Ϊ��ָ��
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
void SLTPushBack(SLTNode ** pphead, SLTDataType x)
{
	assert(pphead);
	//������ͷǿ�����
	SLTNode * newnode =SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else {
		//���ҵ�β�ڵ�
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//ptailָ��ľ���β�ڵ�
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
	//����Ϊ�յ�ʱ��Ҳ���е�ͨ
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	//����ֻ��һ���ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//�����ж���ڵ�
	//�ҵ�β��������ǰһ���ڵ�
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
	//�ȴ洢��һ���ڵ㣬Ȼ��free,Ȼ���ڸ�ֵ
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
SLTNode * SLTFind(SLTNode* phead, SLTDataType x)//��Ӱ��ָ�룬��һ��ָ�뼴��
{
	SLTNode* pcur = phead;//��֤phead���䣬Ҫ��Ȼֻ����һ��
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
			pcur=pcur->next;//����ָ��
	}
	return NULL;
}
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode= SLTBuyNode(x);
	//��pos==*pphead��ֱ��ͷ��
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
void SLTInsertAfter(SLTNode* pos, SLTDataType x)//����Ҫͷ�ڵ㣬��Ϊֱ��pos���иı������
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//���ַ�ʽ��ѡ����ָ��pso->next,��ָ��newnode
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//pos��ͷ�ڵ�
	if (pos == *pphead)
	{
		//ͷɾ
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
void SListDesTroy(SLTNode** pphead)//���٣�һ��һ���ڵ�����
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