#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"



//
// 名字   年龄   性别   电话    住址
// 
// 
// 
// 
//


//菜单栏
void menu(void) {
	printf("************************************\n");
	printf("****** 1. add        2. del    *****\n");
	printf("****** 3. search     4. modify *****\n");
	printf("****** 5. show       6. sort   *****\n");
	printf("****** 7. save       0. exit   *****\n");
	printf("************************************\n");
}

int main() {
	int input = 0;
	struct Contact con;
	//初始化通讯录
	init_contact(&con);

	do
	{
		menu();
		printf("请选择 :> ");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			//增加一个用户信息到通讯录
			Add_Contact(&con);
			break;
		case Del:
			//删除一个用户信息
			Del_Contact(&con);
			break;
		case Search:
			//查询一个用户信息
			Search_Contact(&con);
			break;
		case Modify:
			//修改一个用户信息
			Modify_Contact(&con);
			break;
		case Show:
			//显示通迅息的信息
			Show_Contact(&con);
			break;
		case Sort:
			Sort_Contact(&con);
			break;
		case Save:
			Save_Contact(&con);
			break;
		case Exit:
			Save_Contact(&con);
			Destory_contact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请输入正确的值");
			break;
		}

	} while (input);


	return 0;
}
