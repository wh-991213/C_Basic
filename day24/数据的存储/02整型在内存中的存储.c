#include<stdio.h>
#include<string.h>
#include<limits.h>

int main0201()
{
	//计算机中整型有三种表示方法 - 原码、反码、补码
	//三种表示方法均有符号位和数值位两部分：符号位用0表示正，1表示负
	//1.正数：正数的原、反、补码全都相同
	//2.负数：负数的原码数值位不变，符号位为1；其反码在补码的基础上符号位不变，其它位按位取反 ；其补码为反码+1
	int a = 20;//14 00 00 00
	//00000000 00000000 00000000 00010100 - 原、反、补
	//0x00000014 - 在调试 - 窗口 - 内存中是以十六进制的格式显示的 - 所以将其转换
	int b = -10;//f6 ff ff ff
	//10000000 00000000 00000000 00001010 - 原
	//11111111 11111111 11111111 11110101 - 反
	//11111111 11111111 11111111 11110110 - 补
	//0xFFFFFFF6	

	//由上述可知一个整数在内存里存放的是它的二进制的补码
	//为什么使用补码：
	//是因为使用补码，可以将符号位和数值位统一处理，同时，加法和减法也可以统一处理(CPU只有加法器)
	//此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路

	//观察上面的a和b对应补码的十六进制与在内存中的存储方式是倒着存的
	//      00 00 00 14
	//      FF FF FF F6
	//--------------------------------
	//低地址            高地址 
	//高字节		    低字节
	//--------------------------------
	//      14 00 00 00 - 内存中，小端字节序存储模式：指把数据的低字节内容放到低地址处；高字节内容放到高地址处
	//      F6 FF FF FF 
	//相反，大端字节序存储模式：指把数据的低字节内容放到高地址处；高字节内容放到低地址处
	return 0;
}

int main0202()
{
	//对于上面说的CPU只有加法器
	//1 - 1;
	//  ||
	//1+(-1); - 转换为加法和补码再计算
	//10000000 00000000 00000000 00000001 -   原
	//11111111 11111111 11111111 11111110 -   反
	//11111111 11111111 11111111 11111111 - -1补
	//					+
	//00000000 00000000 00000000 00000001 -  1补
	//    ||       ||	    ||       ||
	//100000000 00000000 00000000 00000000 - 两个用补码表示的数相加时，如果最高位(符号位)有进位，则进位被舍弃
	//    ||       ||       ||       ||
	//000000000 00000000 00000000 0000000 - 0

	return 0;
}

int main0203()
{
	//使用limits.h头文件查看整型的取值范围，格式如下；查看方式 - 转到定义或声明
	INT_MAX;
	UINT_MAX;
	CHAR_MIN;
	return 0;
}

//一、判断当前机器的大小端 
int main0204()
{
	//1.
	int a = 1;
	char *p = (char*)&a;
	if (*p == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

int check_sys()
{
	int a = 1;
	/*char *p = (char*)&a;
	return *p;*/
	//  ||   ||
	return *(char*)&a;
}
//2.
int main0205()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

int check_sys1()
{
	union
	{
		char c;
		int i;
	}u;
	// c/i i i i
	u.i = 1;
	return u.c;
}
//3.
int main0206()
{
	int ret = check_sys1();
	if (1 == ret)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}

//二、输出结果
int main0207()
{
	char a = -1;//-1
	//10000000 00000000 00000000 00000001 - 原
	//11111111 11111111 11111111 11111110 - 反
	//11111111 11111111 11111111 11111111 - 补
	//11111111 - 因为是把-1存到char类型的变量a里，所以只能存放8位；在存放时abc三者都是11111111
	//11111111 11111111 11111111 11111111 - 补 整型提升后
	//11111111 11111111 11111111 11111110 - 反
	//10000000 00000000 00000000 00000001 - 原 -1

	signed char b = -1;//同上 -1
	
	unsigned char c = -1;//255
	//11111111 -	
	//00000000 00000000 00000000 11111111 - 补、反、原 整型提升后 255

	printf("a=%d,b=%d,c=%d", a, b, c);

	//总结：
	//1.如果一个整数存储在一个char类型的变量里时，那么它只能存放这个整数补码的后8位
	//如果要打印一个整数，但这个整数的补码是8位的大小，那么它就要发生整型提升 - 在这个补码的基础上：按符号位提升,无符号按0提升 
	//在内存中是以补码的形式存储，输出时是对应原码的十进制
	return 0;
}

//三、
int main0208()
{
	char a = -128;
	//10000000 00000000 00000000 10000000 - 原
	//11111111 11111111 11111111 01111111 - 反
	//11111111 11111111 11111111 10000000 - 补
	//10000000 - 存到a里
	//11111111 11111111 11111111 10000000 - 补 整型提升
	//11111111 11111111 11111111 10000000 - 补、反、原 - 因为打印的是无符号数
	char b = 128;
	//127+1 -> 01111111+1=10000000=-128 
	printf("%u\n", a);//4294967168
	printf("%u\n", b);//4294967168
	//%d - 打印十进制的有符号数字
	//%u - 打印十进制的无符号数字 
	return 0;
}

//四、
int main0209()
{
	int i = -20;
	//10000000 00000000 00000000 00010100 - 原
	//11111111 11111111 11111111 11101011 - 反
	//11111111 11111111 11111111 11101100 - 补
	unsigned int j = 10;
	//00000000 00000000 00000000 00001010 - 原、反、补

	//i+j
	//11111111 11111111 11111111 11101100 - 补
	//00000000 00000000 00000000 00001010 - 补
	//11111111 11111111 11111111 11110110 - 补 i+j
	//11111111 11111111 11111111 11110101 - 反
	//10000000 00000000 00000000 00001010 - 原 -10

	printf("%d\n", i + j);
	return 0;
}
//五、
int main0210()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);//死循环 - 这里是无符号，所以i永不可能是负；如果在前面定义的是int i; - 有符号，i就会为负数
	} 
	return 0;
}

//六、
int main0211()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));//255
	//strlen以\0为结束标志，这个数组里没有\0，那么这个答案是随机值？
	//signed char类型区间是-128 -> 127
	//|-1,-2,-3... ... -128|,-129,-130......-10000  - 这里-129=-128-1=127
	//|-1,-2,-3... ... -128|,|127,126,...0|...-1000
	//								遇到\0停止
	//128+127=255 - strlen计算的最后的结果

	//			-3     -2       -1 | 0      1       2
	//		-----------------------|-----------------------
	//		-----------------------|-----------------------
	//	-97	-----------------------|-----------------------
	//		-----------------------|-----------------------
	//		-----------------------|-----------------------
	//		-----------------------|----------------------- 77
	//		-----------------------|-----------------------
	//		-----------------------|-----------------------
	//		-----------------------|-----------------------
	//		  -111     -127   -128 | 127     115      107			
	return 0;
}
//七、 
int main0212()
{
	unsigned char i = 0;
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");//死循环 - 255+1 -> 11111111+00000001 =0
	}
	return 0;
}
//总结：五、七 - 对于使用无符号数时，如果条件不适，可能导致程序死循环或与自己预想的结果不同；对于以后使用unsigned时，要注意