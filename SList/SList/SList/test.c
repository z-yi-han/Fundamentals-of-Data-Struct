#include"SList.h"
void SLTistTest01()
{
	////创建几个节点
	////malloc realloc
	//SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	//node1->data = 1;
	//SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	//node2->data = 2;
	//SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	//node3->data = 3;
	//SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//node4->data = 4;
	////用结构体指针解引用将4个节点链接起来
	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = NULL;
	///*调用链表打印*/
	//SLTNode* plist = node1;//指向第一个指针
	//SLTPrintf(plist);
}

void SLTistTest02()
{
	SLTNode * plist = NULL;//定义链表头指针
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	//SLTPushBack(&plist, 5);
	//SLTPushBack(NULL, 5);
	SLTPrintf(plist);
	//测试头插
	/*SLTPushFront(&plist, 6);
	SLTPrintf(plist);
	SLTPushFront(&plist, 7);
	SLTPrintf(plist);
	SLTPushFront(&plist, 8);
	SLTPrintf(plist);*/
	//SLTPushFront(NULL, 9);//assert断言会报错
	//SLTPrintf(plist);
	//测试尾删
	/*SLTPopBack(&plist);
	SLTPrintf(plist);
	SLTPopBack(&plist);
	SLTPrintf(plist);
	SLTPopBack(&plist);
	SLTPrintf(plist);*/
	//测试头删
	/*SLTPopFront(&plist);
	SLTPrintf(plist);
	SLTPopFront(&plist);
	SLTPrintf(plist);
	SLTPopFront(&plist);
	SLTPrintf(plist);*/
	//测试查找
	/*SLTNode* find = SLTFind(plist, 30);
	if (find == NULL)
	{
		printf("没有找到！\n");
	}
	else
	{
		printf("找到了！\n");
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