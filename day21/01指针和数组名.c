#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main0101()
{
	//对于数组名 - 有两个特殊条件
	//1.sizeof(数组名) - 数组名表示整个数组
	//2.&数组名 - 数组名表示整个数组
	//除此之外，所有的数组名都是首元素地址
	int arr[] = { 1,2,3,4 };
	printf("%d\n", sizeof(arr));//16 - sizeof(数组名)计算的是数组的总大小 - 单位是字节
	printf("%d\n", sizeof(arr + 0));//4/8 - 数组名没有满足两个特殊条件，所以是首元素地址
	printf("%d\n", sizeof(*arr));//4 - 数组名没有满足两个特殊条件 - 所以是首元素地址 -解引用找到这个元素并计算
	printf("%d\n", sizeof(arr + 1));//4/8 - 和(arr+0)是一样的，还是首元素地址 - 只不过这次跳过一个元素的地址
	printf("%d\n", sizeof(arr[1]));//4 - 这是第二个元素的大小
	printf("%d\n", sizeof(&arr));//4/8 - &(数组名)取出的是整个数组的地址 
	printf("%d\n", sizeof(*&arr));//16 - &arr是整个数组的地址，再解引用得到整个数组的元素 - 等同于sizeof(arr)
	printf("%d\n", sizeof(&arr + 1));//4/8 - &arr是整个数组的地址 - 整个数组+1跳过一个数组地址 - 最后还是地址 
	printf("%d\n", sizeof(&arr[0]));//4/8 - 第一个元素的地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 跳过一个元素的地址
	return 0;
}

int main0102(void)
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6 - 整个数组大小
	printf("%d\n", sizeof(arr + 0));//4/8 - 地址
	printf("%d\n", sizeof(*arr));//1 - 解引用首元素地址
	printf("%d\n", sizeof(arr[1]));//1 - 数组首元素
	printf("%d\n", sizeof(&arr));//4/8 - 整个数组的地址
	printf("%d\n", sizeof(&arr + 1));//4/8 - 地址的大小是不分高低的
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 跳过1个元素的地址
	return 0;
}

int main0103(void)
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//218 - 218是一个随机值 - 因为strlen函数的结束标志是\0
	printf("%d\n", strlen(arr + 0));//218 - 同上
	//printf("%d\n", strlen(*arr));//err - 这里无值 - 这里strlen后面的参数是'a'=97 - 注意strlen后面的参数应该是地址 
	//printf("%d\n", strlen(arr[1]));//err - 同上
	printf("%d\n", strlen(&arr));//218 - 也是随机值
	printf("%d\n", strlen(&arr + 1));//212 - 随机值 - 不同于上面随机值的原因是因为它跳过了一个数组 - 这两种随机值相差一个char数组
	printf("%d\n", strlen(&arr[0] + 1));//217 - 随机值 - 因为它跳过了一个元素 - 所以相差1
	return 0;
}

int main0104(void)
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7 - sizeof计算的是所占空间的大小 - \0也要被计算
	printf("%d\n", sizeof(arr + 0));//4/8 - 它是一个地址
	printf("%d\n", sizeof(*arr));//1 - 解引用首元素地址
	printf("%d\n", sizeof(arr[1]));//1 - 第二个元素大小
	printf("%d\n", sizeof(&arr));//4/8 - 它是一个数组地址
	printf("%d\n", sizeof(&arr + 1));//4/8 - 它是一个跳过整个数组后地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 它是一个跳过一个元素的地址
	return 0;
}

int main0105(void)
{
//warning:const char*与char(*)[7]的间接寻址不同 - 理论说数组的地址应该存到数组指针里去char(*p)[7] = &arr; - strlen函数的参数类型是const char* - 这也是报警告的原因
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6 - 这里放的是abcdef\0 - strlen这个函数遇\0停止 - 且不会计算
	printf("%d\n", strlen(arr + 0));//6 - 同上
	//printf("%d\n", strlen(*arr));//err - strlen后面的参数放的是地址而不是解引用后的值
	//printf("%d\n", strlen(arr[1]));//err - 同上
	printf("%d\n", strlen(&arr));//6 - 这里指整个数组的地址
	printf("%d\n", strlen(&arr+1));//211 - 随机值
	printf("%d\n", strlen(&arr[0]+1));//5 - 计算第一个元素之后
	return 0;
}	

int main0106(void)
{
	char* p = "abcdef"; //这是一个常量
	printf("%d\n", sizeof(p));//4/8 - 地址
	printf("%d\n", sizeof(p + 1));//4/8 - 地址
	printf("%d\n", sizeof(*p));//1 - 这里并不是把abcdef的地址放进去 - 放进去的是首元素的地址
	printf("%d\n", sizeof(p[0]));//1 - int arr[10]: arr[0] == *(arr+0) - p[0] == *(p+0) == 'a'
	printf("%d\n", sizeof(&p));//4/8 - 它是首元素地址
	printf("%d\n", sizeof(&p + 1));//4/8 - 它是第二个元素的地址
	printf("%d\n", sizeof(&p[0] + 1));//4/8 - 它是第个元素的地址
	return 0;
}

int main0107(void)
{
	char*p = "abcdef";
	printf("%d\n", strlen(p));//6 - p里面存的是a的地址
	printf("%d\n", strlen(p+1));//5 - strlen从b的地址向后数
	//printf("%d\n", strlen(*p));//err - *p是a的值
	//printf("%d\n", strlen(p[0]));//err 
	printf("%d\n", strlen(&p));//6 - 随机值 - p指向a的地址 - &p就是指向p变量的地址 - 所以是随机值
	printf("%d\n", strlen(&p+1));//206 - 随机值
	printf("%d\n", strlen(&p[0]+1)); //5 - 这里是第二个元素的地址
	return 0;
}

int main0108(void)
{
	//sizeof(数组名) - 这里的数组名表示整个数组 - 计算的是整个数组的大小
	//&数组名 - 这里的数组名表示整个数组 - 取出的是整个数组的地址 - &数组名+1也表示整个数组名+1
	//除此之外所有的数组名都表示首元素地址
	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr));//48 - 计算整个数组的元素大小
	printf("%d\n", sizeof(arr[0][0]));//4 - 计算一个元素大小
	printf("%d\n", sizeof(arr[0]));//16 - arr[0]相当于第一行做为一维数组的数组名 - 所以计算的是数组名所在的那一行的元素大小
	printf("%d\n", sizeof(arr[0]+1));//4/8 - 这里sizeof里放的不是arr，也不是arr[0] - 所以它是第一行的首元素地址 - +1最后计算的是第一行的第二个元素的地址 
	printf("%d\n", sizeof(*(arr[0] + 1)));//4 - 这里的arr没有满足特例 - 所以它是第一行的首元素+1后解引用后的值 
	printf("%d\n", sizeof(arr+1));// 4/8 - 这里arr没有满足特例 - 所以arr数组的首元素地址+1得到第二行数组的地址
	printf("%d\n", sizeof(*(arr+1)));//16 - 这里arr并没有满足条件 - 所以它是第一行的地址+1后再解引用 - 得到第二行的数组
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 取第一行的地址加一得到第二行的地址
	printf("%d\n", sizeof(*(&arr[0]+1)));//16 - 取第一行的地址加一得到第二行的地址再解引用
	printf("%d\n", sizeof(*arr));//16 - 还有一种方法是对比一维数组 - 一维数组sizeof(*arr)得到的是首元素 - 所以这里sizeof(*arr)得到的也是首元素
	printf("%d\n", sizeof(arr[3]));//16 - 这个数组是3行4列，而这里找的是第4行，所以是err？？？ - 其实sizeof里面的表达式并不会计算，也不会去访问第四行 - 这里sizeof只是根据表达式的类型去计算它的大小
	return 0;
}

int main0109(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&arr + 1);//取整个数组的地址+1 - 再强制类型转换成指针类型 - 数组指针类型 - 数组指针类型并不能存到整型指针里去 - 但ptr指向的值还是不变的
	printf("%d,%d\n", *(arr + 1), *(ptr - 1));//2,5 - 首元素地址+1再解引用 - ptr是整型指针，-1就向前挪动一个整型 - 再解引用找到5
	return 0;
}


struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//这里就是一个结构体指针
//假设p的值为0x100000,如下表达式的值分别是多少？
//已知，结构体Test类型的变量大小是20个字节
int main0110(void)
{
	//p = 0x100000;//这里是整数 - 整数转给Test*结构体类型是有问题的 - 所以强制类型转换成结构体指针
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);//0x00100014 - p+1跳过一个结构体 - 就是0x00100020 
	printf("%p\n", (unsigned long)p + 0x1);//0x00100001 - 把p强制类型转换成long整型类型 - 把0x100000转换成十进制1048576 - 加一得到1048577 - 1048576转换成十六进制0x00100001
	printf("%p\n", (unsigned int*)p + 0x1);//0x00100014 - 把p强转为无符号整型指针 - 再加一跳过4个字节
	//指针+-整数 - 取决指针类型 
	return 0;
}

int main0111(void)
{
	int arr[4] = { 1,2,3,4 };
	//01 00 00 00|02 00 00 00|03 00 00 00|04 00 00 00 - 小端存储模式
	int* ptr1 = (int*)(&arr + 1);//跳过整个数组 - 再强制类型转换为整型指针 - 再把这个整型指针赋给ptr1
	int* ptr2 = (int*)((int)arr + 1);//数组首元素强制类型转换成整型再+1 - 再强制类型转换为整型指针 - 然后再赋给ptr2
	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1] = *(ptr1+(-1)) == *(ptr1-1) - ptr1是一个整型指针，所以它向前跳过一个整型并解引用打印结果是4 - 对应十六进制0x00000004
	//ptr是一个整型指针 - 它指向第二个字节 - 整型指针解引用访问4个字节 - 0x02000000
	return 0;
}

int main0112(void)
{
	int arr[3][2] = {(0, 1), (2, 3), (4, 5)}; //- 逗号表达式 - 结果是最后一个结果 - 所以结果依次是1，3，5 - 所以初始化为1，3，5，0，0，0
	int* p;
	p = arr[0];//arr[0]是第一行的数组名的首元素
	printf("%d", arr[0]);//所以这里的结果是1
	return 0;
}

int main0113(void)
{
	int arr[5][5];
	int(*p)[4];
	p = arr;
	printf("%p,%d\n", &p[4][2] - &arr[4][2], &p[4][2] - &arr[4][2]);
	//对于arr数组
	//  arr[0]    arr[1]	arr[2]	  arr[3]    arr[4]
	//* * * * *|* * * * *|* * * * *|* * * * *|* * * * *
	//											  |
	//										  arr[4][2] 
	//那p[4][2]怎么找 - p是指针数组 - p是一个指向4个整型元素的数组的指针；这里强行把arr(这里是首元素地址)赋给p - 而第一行是5个元素的数组 - warning:int(*)[4]和int(*)[5]数组下标不同；但p其实还是指向首元素，因为是把这个地址赋给了p,只是类型不符而已
	//因为它是指向一个整型数组的指针
	//所以对于p指针
	//  arr[0]    arr[1]	arr[2]	  arr[3]    arr[4]
	//* * * * *|* * * * *|* * * * *|* * * * *|* * * * *
	//|       |       |       |       |
	//|       |       |       |           |
	//								 p[4][2] == *(*(p+4)+2) - p+4解引用向后拿到4个元素的数组相当于数组名 - +2相当于首元素+2 - 再解引用拿到此元素
	//最后arr[4][2]和p[4][2]的位置都找到了 - 再进行上面的运算
	//p的地址相对arr的地址要小 - 所以得到的是-4 - 这里%d打印-4没问题
	//但是进行%p的形式打印，打印的是对应内存的值 - 自然没关注有符号或无符号
	//-4 原码 10000000 00000000 00000000 00000100
	//   反码 11111111 11111111 11111111 11111011
	//   补码 11111111 11111111 11111111 11111100 - 以%p的形式打印，就不存在正负数的概念 - 那就认为内存里存的这个补码就是它的原码
	//		  FFFFFFFC
	return 0;
}

int main0114(void)
{
	int arr[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&arr + 1);//跳过一个二维数组
	int* ptr2 = (int*)(*(arr + 1));//第二行首元素地址
	//int arr[10]={1,2,3,4,5};
	//int* p = arr;
	//*(p+2) == *(arr+2) == arr[2]
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	//10，5

	return 0;
}

int main0115(void)
{
	char* arr[] = { "work","at","alibaba" };// - 指针数组 - 且每个char*指向的是每个字符串的首地址
	char** pa = arr;//int * p; p+1;- 跳过一个整型； 同理char* *pa=arr; - pa++跳过一个char*变量
	pa++;
	printf("%s\n", *pa);//at 
	return 0;
}

int main0116(void)
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	//			  c			cp				cpp
	//"ENTER" - char*		c+3 - 对应F		cpp又指向cp的首元素地址
	//"NEW"   - char*		c+2 - 对应P
	//"POINT" - char*		c+1 - 对应N
	//"FIRST" - char*		c   - 对应E
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *--*++cpp + 3);//ER
	printf("%s\n", *cpp[-2] + 3);//ST - *(*(cpp-2))+3
	printf("%s\n", cpp[-1][-1] + 1);//EW - *(*(cpp-1)-1)
	
	return 0;
}
