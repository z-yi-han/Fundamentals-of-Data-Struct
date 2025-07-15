#pragma once
#include"Contact.h"
#include"SeqList.h"
#include<stdio.h>
//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con)
{
	//ʵ�����Ƕ�˳���ĳ�ʼ�����Ѿ�ʵ�ֺ���
	SLInit(con);
}
//ͨѶ¼������
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}
//ͨѶ¼�������
void ContactAdd(Contact* con)
{
	//��ȡ�û�������������Ա����䡢�绰
	peoInfo info;
	printf("������Ҫ��ӵ���ϵ������:\n ");
	scanf("%s", info.name);

	printf("������Ҫ��ӵ���ϵ���Ա�:\n ");
	scanf("%s", info.gender);

	printf("������Ҫ��ӵ���ϵ������:\n ");
	scanf("%d", &info.age);

	printf("������Ҫ��ӵ���ϵ�˵绰:\n ");
	scanf("%s", info.tel);

	printf("������Ҫ��ӵ���ϵ�˵�ַ:\n ");
	scanf("%s", info.adde);
	//����Ϣ��ӵ�˳�����
	SLPushBack(con, info);
}
//�����Ƿ������ϵ��
int FindByname(Contact* con, char name[])
{
	//����ͨѶ¼�������Ƿ���ڸ���ϵ��
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->arr[i].name,name) == 0)
		{
			return i; //�����ҵ�������
		}
	}
	return -1; //δ�ҵ�����-1
}
//ͨѶ¼ɾ������
void ContactDel(Contact* con)
{
	//�Ȳ���Ҫɾ������ϵ���Ƿ����
	//����
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ������:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("δ�ҵ�����ϵ�ˣ�ɾ��ʧ�ܣ�\n");
		return; //δ�ҵ���ϵ�ˣ�ֱ�ӷ���
	}
	//������ɾ��
	SLErase(con, find);
	printf("��ϵ��%sɾ���ɹ���\n", name);
}
//չʾͨѶ¼����
void ContactShow(Contact* con)
{
	//��ͷ������ �Ա� ���� �绰 ��ַ
	printf("%s %s %s %s %s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//����ͨѶ¼�����ÿ����ϵ�˵���Ϣ
	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %3s %3d %3s %3s\n",//�����ֶ����������ʽ
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].adde);
	}
}
//ͨѶ¼���޸�
void ContactModify(Contact* con)
{
	//Ҫ�޸ĵ���ϵ�˴���
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ������:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("δ�ҵ�����ϵ�ˣ��޸�ʧ�ܣ�\n");
		return; //δ�ҵ���ϵ�ˣ�ֱ�ӷ���
	}
	//�������޸�
	printf("�������µ�����:\n ");
	scanf("%s", con->arr[find].name);
	printf("�������µ��Ա�:\n ");
	scanf("%s", con->arr[find].gender);
	printf("�������µ�����:\n ");
	scanf("%d", con->arr[find].age);
	printf("�������µĵ绰:\n ");
	scanf("%s", con->arr[find].tel);
	printf("�������µ�סַ:\n ");
	scanf("%s", con->arr[find].adde);
	printf("�޸ĳɹ���\n");
}
//ͨѶ¼�Ĳ���
void ContactFind(Contact* con)
{
	//Ҫ���ҵ���ϵ�˴���
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ������:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("δ�ҵ�����ϵ�ˣ�\n");
		return; //δ�ҵ���ϵ�ˣ�ֱ�ӷ���
	}
	//�����������Ϣ
	printf("����: %s\n", con->arr[find].name);
	printf("�Ա�: %s\n", con->arr[find].gender);
	printf("����: %d\n", con->arr[find].age);
	printf("�绰: %s\n", con->arr[find].tel);
	printf("��ַ: %s\n", con->arr[find].adde);
}