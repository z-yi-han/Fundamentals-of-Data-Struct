#pragma once
#define _CRT_SECURE_NO_WARNINGS
//联系人数据
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100
typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char adde[ADDR_MAX];
}peoInfo;
//前置声明
struct SeqList;///因为互相包含导致矛盾，所以直接前置声明
//要用到顺序表相关方法，对通讯录的操作本质就是对顺序表进行操作
//给顺序表改个名字，叫做通讯录
typedef struct SeqList Contact;//SL在顺序表头文件定义好结构之后才起的，所以不能用SL，只能直接用struct SeqList，也就是用到顺序表最初始的结构
//通讯录相关方法
//通讯录的初始化
void ContactInit(Contact * con);
//通讯录的销毁
void ContactDestroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);