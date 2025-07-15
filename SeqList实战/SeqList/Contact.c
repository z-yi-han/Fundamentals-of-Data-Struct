#pragma once
#include"Contact.h"
#include"SeqList.h"
#include<stdio.h>
//通讯录的初始化
void ContactInit(Contact* con)
{
	//实际上是对顺序表的初始化，已经实现好了
	SLInit(con);
}
//通讯录的销毁
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}
//通讯录添加数据
void ContactAdd(Contact* con)
{
	//获取用户输入的姓名、性别、年龄、电话
	peoInfo info;
	printf("请输入要添加的联系人姓名:\n ");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别:\n ");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄:\n ");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话:\n ");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人地址:\n ");
	scanf("%s", info.adde);
	//将信息添加到顺序表中
	SLPushBack(con, info);
}
//查找是否存在联系人
int FindByname(Contact* con, char name[])
{
	//遍历通讯录，查找是否存在该联系人
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->arr[i].name,name) == 0)
		{
			return i; //返回找到的索引
		}
	}
	return -1; //未找到返回-1
}
//通讯录删除数据
void ContactDel(Contact* con)
{
	//先查找要删除的联系人是否存在
	//查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("未找到该联系人，删除失败！\n");
		return; //未找到联系人，直接返回
	}
	//存在则删除
	SLErase(con, find);
	printf("联系人%s删除成功！\n", name);
}
//展示通讯录数据
void ContactShow(Contact* con)
{
	//表头：姓名 性别 年龄 电话 地址
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	//遍历通讯录，输出每个联系人的信息
	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %3s %3d %3s %3s\n",//可以手动调整输出格式
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].adde);
	}
}
//通讯录的修改
void ContactModify(Contact* con)
{
	//要修改的联系人存在
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("未找到该联系人，修改失败！\n");
		return; //未找到联系人，直接返回
	}
	//存在则修改
	printf("请输入新的姓名:\n ");
	scanf("%s", con->arr[find].name);
	printf("请输入新的性别:\n ");
	scanf("%s", con->arr[find].gender);
	printf("请输入新的年龄:\n ");
	scanf("%d", con->arr[find].age);
	printf("请输入新的电话:\n ");
	scanf("%s", con->arr[find].tel);
	printf("请输入新的住址:\n ");
	scanf("%s", con->arr[find].adde);
	printf("修改成功！\n");
}
//通讯录的查找
void ContactFind(Contact* con)
{
	//要查找的联系人存在
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名:\n ");
	scanf("%s", name);
	int find = FindByname(con, name);
	if (find < 0)
	{
		printf("未找到该联系人！\n");
		return; //未找到联系人，直接返回
	}
	//存在则输出信息
	printf("姓名: %s\n", con->arr[find].name);
	printf("性别: %s\n", con->arr[find].gender);
	printf("年龄: %d\n", con->arr[find].age);
	printf("电话: %s\n", con->arr[find].tel);
	printf("地址: %s\n", con->arr[find].adde);
}