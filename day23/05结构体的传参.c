#include<stdio.h>


struct St
{
	int a;
	char c;
	double d;
};
void Init1(struct St temp)
{
	temp.a = 100;	
	temp.c = 'w';
	temp.d = 3.14;
}
void Init2(struct St* temp)
{
	temp->a = 100;
	temp->c = 'w';
	temp->d = 3.14;
}
void print3(struct St temp)
{
	printf("%d %c %lf\n", temp.a, temp.c, temp.d);
}
void print4(const struct St* temp)
{
	printf("%d %c %lf\n", temp->a, temp->c, temp->d);
}
int main0501()
{
	struct St t = { 0 }; 
	//Init1(t);//值传递 - 特点是单向传递，即主调函数调用时给形参分配存储单元，把实参的值传递给形参，在调用结束后，形参的存储单元被释放，所以形参的任何变化都不会影响到实参
	Init2(&t);//地址传递 

	print3(t);//输出函数
	print4(&t);//相对于传t来说，&t的权限更大
	//对比print3 - 传值和print4 - 传址来说哪种方式更好？？？
	//print3 - 函数传参时，参数是需要压栈的，会有时间和空间上的系统开销
	//print4 - 在传参的时候传的是一个地址，不管这个结构体多大 - 都是4或8个字节 - 未来在结构体传参的时候尽量传址

	//这里还有一个疑问：传地址过去 - 可以改变值的内容 - 但print4函数又不改变，只是打印 - 那传t是不是更安全？？？
	//如果担心传址改变结构体的内容时，可以使用const来限制
	return 0;
}


typedef struct Stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu;

void print1(Stu ss)//在接收结构体变量时必须要用结构体类型接收，ss可以是任意
{
	printf("name:%s\n", ss.name);
	printf("age:%d\n", ss.age);
	printf("tele:%s\n", ss.tele);
	printf("sex:%s\n", ss.sex);
}

//void print2(Stu* ps)//在接收结构体变量的地址时必须要用能接收结构体变量地址的指针，ps也可以是任意。注意这里的参数是typedef重新定义的结构体类型名，如果没有typedef定义，就要写全结构体类型struct Stu* ps
//{
//	printf("name:%s\n", ps->name);//对于通过指针去访问结构体成员时必须是：结构体类型->结构体成员变量名
//	printf("age:%d\n", ps->age);	
//	printf("tele:%s\n", ps->tele);
//	printf("sex:%s\n", ps->sex);
//}
int main0502()
{
	Stu s = { "李四",40,"15550882","男" };
	print1(s);//结构体传参使用结构体变量做为参数
	//print2(&s);//也可以把结构体变量的地址做为参数
	//print1和print2哪种方式更好？？？
	//首选print2 - 任何一次函数调用都会在内存的栈区上申请一块空间
	//对于print1来说，s是实参，传给上面的形参。 - 形参是实参的一份临时拷贝 - 必然要拷贝一份一样的数据 - 如果数据庞大，那将会浪费大量的资源空间 - 同时也会浪费时间
	//对于print2来说，无论这个结构体多大，传递的是地址，一个地址无非就是4或8个字节，

	//总结：函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销较大，会导致性能的下降
	//结构体传参的时候，要传结构体的地址

	return 0; 
}


int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
//补充：
int main0503(void)
{
	int a = 10;
	int b = 20;
	int ret = 0;
	ret = Add(a, b);
	return 0;
}
//         栈区                    堆区					  静态区
// ---------------------    -------------------		-------------------
// |     局部变量      |    |   动态内存分配  |		|	 全局变量     |
// | 函数的形式参数	   |	|	malloc/free	  |     |				  |
// |函数调用开辟的空间 |	|	realloc       |		|    静态变量	  |
// |                   |	|	calloc        |		|				  |
//  ------------------	    -------------------		-------------------
//对于栈区：先进后出
