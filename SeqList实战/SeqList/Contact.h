#pragma once
#define _CRT_SECURE_NO_WARNINGS
//��ϵ������
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
//ǰ������
struct SeqList;///��Ϊ�����������ì�ܣ�����ֱ��ǰ������
//Ҫ�õ�˳�����ط�������ͨѶ¼�Ĳ������ʾ��Ƕ�˳�����в���
//��˳���ĸ����֣�����ͨѶ¼
typedef struct SeqList Contact;//SL��˳���ͷ�ļ�����ýṹ֮�����ģ����Բ�����SL��ֻ��ֱ����struct SeqList��Ҳ�����õ�˳������ʼ�Ľṹ
//ͨѶ¼��ط���
//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact * con);
//ͨѶ¼������
void ContactDestroy(Contact* con);
//ͨѶ¼�������
void ContactAdd(Contact* con);
//ͨѶ¼ɾ������
void ContactDel(Contact* con);
//ͨѶ¼���޸�
void ContactModify(Contact* con);
//չʾͨѶ¼����
void ContactShow(Contact* con);