#include"SList.h"
void SLTistTest01()
{
	////���������ڵ�
	////malloc realloc
	//SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	//node1->data = 1;
	//SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	//node2->data = 2;
	//SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	//node3->data = 3;
	//SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//node4->data = 4;
	////�ýṹ��ָ������ý�4���ڵ���������
	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = NULL;
	///*���������ӡ*/
	//SLTNode* plist = node1;//ָ���һ��ָ��
	//SLTPrintf(plist);
}

void SLTistTest02()
{
	SLTNode * plist = NULL;//��������ͷָ��
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	//SLTPushBack(&plist, 5);
	//SLTPushBack(NULL, 5);
	SLTPrintf(plist);
	//����ͷ��
	/*SLTPushFront(&plist, 6);
	SLTPrintf(plist);
	SLTPushFront(&plist, 7);
	SLTPrintf(plist);
	SLTPushFront(&plist, 8);
	SLTPrintf(plist);*/
	//SLTPushFront(NULL, 9);//assert���Իᱨ��
	//SLTPrintf(plist);
	//����βɾ
	/*SLTPopBack(&plist);
	SLTPrintf(plist);
	SLTPopBack(&plist);
	SLTPrintf(plist);
	SLTPopBack(&plist);
	SLTPrintf(plist);*/
	//����ͷɾ
	/*SLTPopFront(&plist);
	SLTPrintf(plist);
	SLTPopFront(&plist);
	SLTPrintf(plist);
	SLTPopFront(&plist);
	SLTPrintf(plist);*/
	//���Բ���
	/*SLTNode* find = SLTFind(plist, 30);
	if (find == NULL)
	{
		printf("û���ҵ���\n");
	}
	else
	{
		printf("�ҵ��ˣ�\n");
	}
	SListDesTroy(&plist);
	SLTPrintf(plist);*/
}
int main()
{
	//SLTistTest01();
	SLTistTest02();
	return 0;
}