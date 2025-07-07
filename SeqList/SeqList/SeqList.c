#include"SeqList.h"
void SLInit(SL* ps)//动态顺序表初始化
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps)//动态顺序表的销毁
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->size = 0;
}
void SLCheckCapacity(SL* ps)//检查空间够不够
{
	if (ps->capacity == ps->size)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
void SLPrint(SL s)//打印顺序表
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
void SLPushFront(SL* ps, SLDataType x)//头插
{
	assert(ps);
	SLCheckCapacity(ps);
	//让顺序表中已有的元素整体向后移动一位
	for (int i = ps->size; i>0; i++)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SLPushBack(SL* ps, SLDataType x)//尾插
{
	assert(ps);
	SLCheckCapacity(ps);
	//直接插入即可
	ps->arr[ps->size++] = x;
}
void SLPopBack(SL* ps)//尾删
{
	assert(ps);
	assert(ps->size);
	--ps->size;
}
void SLPopFront(SL* ps)//头删
{
	assert(ps);
	assert(ps->size);

	//数据整体往前挪动一位
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1]; //arr[size-2] = arr[size-1]
	}
	ps->size--;
}