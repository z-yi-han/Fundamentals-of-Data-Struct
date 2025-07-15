#include"SeqList.h"
void SLInit(SL* ps)//��̬˳����ʼ��
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps)//��̬˳��������
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->size = 0;
}
void SLCheckCapacity(SL* ps)//���ռ乻����
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
		//�ռ�����ɹ�
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
//void SLPrint(SL s)//��ӡ˳���
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}
void SLPushFront(SL* ps, SLDataType x)//ͷ��
{
	assert(ps);
	SLCheckCapacity(ps);
	//��˳��������е�Ԫ����������ƶ�һλ
	for (int i = ps->size; i>0; i++)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SLPushBack(SL* ps, SLDataType x)//β��
{
	assert(ps);
	SLCheckCapacity(ps);
	//ֱ�Ӳ��뼴��
	ps->arr[ps->size++] = x;
}
void SLPopBack(SL* ps)//βɾ
{
	assert(ps);
	assert(ps->size);
	--ps->size;
}
void SLPopFront(SL* ps)//ͷɾ
{
	assert(ps);
	assert(ps->size);

	//����������ǰŲ��һλ
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1]; //arr[size-2] = arr[size-1]
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//�������ݣ��ռ乻����
	SLCheckCapacity(ps);
	//��pos��֮���������������Ų��һλ
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[pos+1] = arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}
//ɾ��ָ��λ�õ�����
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//����
//int SLFind(SL* ps, SLDataType x)
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x)
//		{
//			//�ҵ���
//			return i;
//		}
//	}
//	//û���ҵ�
//	return -1;
//}