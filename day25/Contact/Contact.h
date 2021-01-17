//宏定义
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#pragma warning(disable:4996)

//声明
enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

#include<stdio.h>
#include<string.h>
//一个用户的信息
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//通讯录类型 
struct Contact
{
	struct PeoInfo data [MAX];//存放一个信息
	int size;//记录当前已经有的元素个数
};

//函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DefContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);