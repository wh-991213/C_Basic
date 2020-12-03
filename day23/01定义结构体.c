#include<stdio.h>


//声明结构体
//结构体类型的成员可以是不同类型的变量 - 对立数组的成员必须是相同类型的元素
//结构体格式如下：
//struct tag   -  struct:结构体关键字  tag:结构体标签(自定义)   struct tag:结构体类型
//{
//	  member - list;  - 成员列表
//}variable - list; - 变量列表

//这里创建出来的结构体类型并没有占据内存空间
struct Stu
{
	char name[20];
	char tele[12];
	char sex[10];
	int age; 
}s4, s5, s6;//定义结构体变量
struct Stu s3;//这里s3/s3/s5/s6都是全局变量

int main0101()
{
	//创建的结构体局部变量s1 
	struct Stu s1;
	struct Stu s2;
	return 0;
}


//匿名结构体类型：只能使用一次
struct
{
	int a;
	char c;
}sa;//当出现匿名结构体时，可以不要标签，但是必须在此处创建变量
//匿名结构体指针类型
struct
{
	int a;
	char c;
}*pa;
int main0102()
{
	pa = &sa;//warning:从*到*的类型不兼容 - 虽然两个匿名结构体成员是一样的，但是编译器会把它们认为是两种不同独立的类型
	return 0;
}
	
 
//结构体自引用
struct Node
{
	int data;
	struct Node*next;//结构体找到同类型其它的变量，类型* + next
	//struct Node n;//err - 结构体的成员不能包含自己，但可以包含其它结构体
}n;

//typedef简化结构体类型
typedef struct Node1
{
	int data;
	//Node2* next1;//err  - 这里使用typedef定义的类型名还没有创建，所以还不能使用Node2
	struct Node1*next1;//ok
}Node2;//这里使用typedef关键字把struct Node1类型重新起了一个名字叫Node2 - 类型

int main0103(void)
{
	struct Node n1;
	//| | |
	//| | |
	Node2 n2;
	return 0;
}

