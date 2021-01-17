#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"

void menu()
{
	printf("**********************************************\n");
	printf("*********1.add                  2.def*********\n");
	printf("*********3.search               4.modify******\n");
	printf("*********5.show                 6.sort********\n");
	printf("*********0.exit                 **************\n");
	printf("**********************************************\n");

}
int main()
{
	int input = 0;
	//菜单循环前创建通讯录 - 对于一个用户的信息 - 名字、年龄、性别、电话、地址 - 结构体
	struct Contact con;//con就是通讯录，里面包含：1000个元素和size
	//通讯录初始化
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DefContact(&con);
			break;
		case SEARCH: 
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			break;
			printf("退出通讯录\n");
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
