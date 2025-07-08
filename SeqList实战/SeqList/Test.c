#include"SeqList.h"
//void SLTest01()
//{
//	SL sl;
//	SLInit(&sl);
//	//ɾĲ
//	//β
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);//1 2 3 4
//
//	//SLPushFront(&sl, 5);
//	//SLPushFront(&sl, 6);
//
//	//βɾ
//	SLPopBack(&sl);
//	SLPrint(sl);//1 2 3 
//	SLPopBack(&sl);
//	SLPrint(sl);
//	SLPopBack(&sl);
//	SLPrint(sl);
//	SLPopBack(&sl);
//	SLPrint(sl);
//	SLPopFront(&sl);
//	SLPrint(sl);
//	//...........
//	SLDestroy(&sl);
//	/*测试指定位置之前插入数据*/
//	SLInsert(&sl, 1, 99);
//	SLInsert(&sl, sl.size, 88);
//
//	//测试删除指定位置的数据
//	SLErase(&sl, 1);
//	SLPrint(sl);//1 3  4
//
//	//测试顺序表的查找
//	int find = SLFind(&sl, 40);
//	if (find < 0)
//	{
//		printf("没有找到！\n");
//	}
//	else {
//		printf("找到了！下标为%d\n",find);
//	}
//	SLDestroy(&sl);
//}
//
//
//通讯录的测试方法


//void ContactTest()
//{
//	Contact con;//创建的通讯录对象，实际上是顺序表对象，等价于SL sl
//	ContactInit(&con);//初始化通讯录对象
//	ContactAdd(&con);//添加联系人
//	ContactAdd(&con);//添加联系人
//	//ContactDel(&con);//删除联系人
//	//ContactDel(&con);//删除联系人
//	ContactModify(&con);//修改
//	ContactShow(&con);//显示
//	ContactDestroy(&con);//销毁顺序表对象
//}
void menu()
{
	printf("******************通讯录******************\n");
	printf("*******1.增加联系人   2.删除联系人********\n");
	printf("*******3.修改联系人   4.查找联系人********\n");
	printf("*******5.展示联系人   0.   退出  *********\n");
	printf("******************************************\n");
}

int main()
{
	/*SLTest01();*/
	/*ContactTest();*/
	int op = -1;
	Contact con; //创建一个通讯录对象
	do {
		menu();
		printf("请选择您的操作: \n");
		scanf("%d", &op);
		//要根据对应的op执行不同的操作
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出通讯录....\n");
			break;
		default:
			printf("输入错误，请重新选择您的操作！\n");
			break;
		}
	} while (op!=0);
	ContactDestroy(&con); //销毁通讯录对象
	return 0;
}