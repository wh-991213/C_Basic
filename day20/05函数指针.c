#include<stdio.h>

//数组指针 - 指向数组的指针
//函数指针 - 指向函数的指针 - 存放函数地址的一个指针 - 函数真的有地址吗？？？
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main0501()
{
	int a = 10;
	int b = 20;
	//printf("%d\n", Add(a, b));
	//printf("%p\n", Add);
	//printf("%p\n", &Add);
	//这就是Add函数的地址，那&Add和Add的意义是不是一样的？？？
	//如果是int arr[10]={0}; 则&arr是数组的地址；arr是首元素的地址
	//对于函数的地址来说，&函数名和函数名的意义是一样的

	//函数的地址存储 - 函数指针
	//int *pa(int, int) = &Add;//err - pa是一个函数 - 它有两个int参数 - int*就是它的返回类型 -我们希望pa是一个指针存放函数地址
	int(*pa)(int, int) = &Add;//pa是一个指针 - 它指向一个函数，这个函数有两个int参数 - 函数的返回类型是int
	//验证pa是否存储函数地址
	printf("%d\n", (*pa)(2, 3));//5
	return 0;
}

void Print(char*str)
{
	printf("%s\n", str);
}
int main0502(void)
{

	//存放Print函数的地址 
	void(*p)(char*) = Print;
	//通过指针调用这个函数
	(*p)("hello world");
	return 0;
}
//我们再回到前面的代码
int Add1(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main0503(void)
{
	int a = 10;
	int b = 20;
	int(*pa)(int, int) = Add1;
	//思考在函数调用中(*pa)中的*到底是什么意思呢？？？
	printf("%d\n", (*pa)(2, 3));
	//pa如果是指针，我想找到它所指向的那个函数并调用 - 先解引用 - 这是对于指针理解的最初的印象
	//能否这样写？ - printf("%d\n",*pa(2,3));此时pa先和括号结合，得到5后再解引用。报的错误是非法的间接寻址
	printf("%d\n", Add1(2, 3));//假设没有pa这个概念的话
	printf("%d\n", (pa)(2, 3));//Add和pa是一回事
	//发现结果是一样的，说明在函数调用这里的*是一个摆设 - 对于函数指针来说这颗*其实没有太大的价值
	return 0;
}

//观察分析代码,此代码来自《C陷阱和缺陷》
//1.
//(*(void(*)())0)(); - 这是函数调用
//把0强制类型转换成void(*)()函数指针类型 - 该指针指向的函数是无参，返回类型是void，当0变成函数地址后，对它进行解引用操作 - 再去调用以0为地址的该函数。


//2.
//void(*signal(int,void(*)(int)))(int) - 这是函数声明 - 函数名、函数参数、函数的返回类型
//signal是一个函数 - 它有两个参数：一个是int，一个是函数指针 - 一个函数：函数名、函数参数、函数的返回类型（未知）
//对于一个函数来说int add(int,int)。函数名是add，参数是int int,对于函数返回类型（去掉函数名和参数）就是int
//同理void(*            )(int) - 说明signal的返回类型是函数指针
//可否这样写？ - void(*)(int)(*signal(int,void(*)(int)) - 这种写法是错误的

//其实挺难理解的，这段代码能不能让它更精简点
//void(*      signal(int, void(*)(int))       )(int) - 这是原代码
//使用typedef关键字
//例如：typedef unsigned int uint; - 把unsigned int 简化为uint
//同理typedef void(*)(int) pfun_t;？？？- 对于函数指针是不可以这样写的 
//typedef void(* pfun_t)(int) - 应该这样写。此时pfun_t就是函数指针类型
//所以简化得到 pfun_t signal(int,pfun_t)

