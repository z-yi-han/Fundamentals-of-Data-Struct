#include"List.h"
void ListTest01()
{
	/*LTNode* plist = NULL;
	LTInit(&plist);*/
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);
	/*LTPushFront(plist, 1);
	LTPrint(plist);
	LTPushFront(plist, 2);
	LTPrint(plist);
	LTPushFront(plist, 3);
	LTPrint(plist);*/
	LTPopBack(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTDestroy(plist);
	plist = NULL;
}
int main()
{
	ListTest01();
	return 0;
}