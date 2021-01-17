#include"Contact.h"


void InitContact(struct Contact* ps)
{
	//memset函数(将一段内存空间填入某值)，表头文件<string.h>
	//函数原型void* memset(void* s,int c,size_t n);
	//memset会将参数s所指的内存区域前n个字节以参数c填入，然后返回指向s的指针。在编写程序时，若需要将某一数组初始化，memset会相当方便
	//注意参数c类型虽是int，但必须是unsigned char 所以是0-255之间

	memset(ps->data, 0, sizeof(ps->data));//这里sizeof计算的是整个数组的大小
	ps->size = 0;
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps ->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}

	return -1;
}
void DefContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//因为后面不止一次需要查找，所以这里直接封装一个查找名字的函数，解决代码的冗余
	//成功则返回名字所在元素的下标，否则返回-1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for ( j = pos; j <ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("需要修改人的信息不存在\n");
	}
	else
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");
}

void SortContact(struct Contact* ps)
{

}


