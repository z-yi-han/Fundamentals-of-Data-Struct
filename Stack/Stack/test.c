#include<stdio.h>
#include<stdlib.h>
//
//int main()
//{
//	// ԭ������
//	// �������
//	int* p1 = (int*)malloc(8);
//	printf("%p\n", p1);
//
//	int* p2 = (int*)realloc(p1, 80);
//	printf("%p\n", p2);
//
//	free(p2);
//
//
//	int i = 0;
//	int ret1 = ++i;
//
//	int ret2 = i++;
//
//
//
//	return 0;
//}

#include"Stack.h"

//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//
//	//printf("%d\n", STTop(&s));
//
//	STDestroy(&s);
//
//	return 0;
//}

int main()
{
	// ��ջ��1 2 3 4
	// ��ջ��4 3 2 1  /  2 4 3 1
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);

	printf("%d ", STTop(&s));
	STPop(&s);

	STPush(&s, 3);
	STPush(&s, 4);

	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}

	STDestroy(&s);
}