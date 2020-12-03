#include<stdio.h>

/*
struct S
{
	//结构体里的成员都是各自独立的,用分号隔开
};
enum Em	
{
	//枚举里不是成员，而是可能取值，用逗号隔开
};
*/
//联合  联合体  共用体
//联合体类型的定义：
//联合体也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间，所以联合体也叫共用体
//union联合体关键字
union Un
{
	char c;//1
	int i;//4
};
int main0901()

{
	union Un u;
	printf("%d\n",sizeof(u));//4B 

	//打印地址
	printf("%p\n", &u);
	printf("%p\n", &(u.c));
	printf("%p\n", &(u.i));
	//发现它们的地址竟然是相同的
	//u在内存中的布局
	//[c/i][i][i][i] - 
	//联合体的特点：联合的成员是共用同一块空间的，这样一个联合变量的大小，至少是最大成员的大小(因为联合至少得有能力保存最大的那个成员) - 也就是说i和c都要放的下的话，大小至少是最大的那个成员的大小
	//既然联合体会把它的成员共用同一块空间 - 能不能同时使用i和c？？？ - 它们之间的空间互相干涉所以不能
	return 0;
}



//判断当前机器的大小端存储 - 大端存储or小端存储
//讨论一个数据，放在内存中的存放的字节顺序
//大小端字节序问题
int main0902(void)
{
	//int a = ox11223344; //ox11 22 33 44 - 4个字节
	//	 低地址------------------高地址
	//...[][][][11][22][33][44][][][][][][][][]... 
	//把一个数的低字节内容放到高地址处，高字节内容放到低地址处。这种存储方式叫做大端字节序存储模式

	//...[][][][44][33][22][11][][][][][][][][]...
	//把一个数的低字节内容放到低地址处，高字节内容放到高地址处。这种存储方式叫做小端字节序存储模式



	//1对应的十六进制是ox00 00 00 01
	int a = 1;
	//这里a是4个字节，取a的地址后，再强制类型转换成char*类型。这里就只能往后访问一个字节
	if(1== *(char*)&a)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}	



//这里重新另写一种方式，因为上面的比较戳 
int check_sys()
{
	int a = 1;
	//返回1表示小端
	//返回0表示大端
	return *(char*)&a;
}
int main0903(void)
{
	int ret = check_sys();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}




//再来个高级点的方法   联合体
int check_sys1()
{
	//这里也可以将联合体标签舍弃，就是匿名结构体类型，因为这里只使用一次
	union //Un1
	{
		char c;
		int i;
	}u;
	//这里就会涉及到大小端存储
	u.i = 1;
	//然后巧妙的拿出第一个字节并返回；；利用了联合体的特性-----联合体的成员是共用一块空间的
	//返回1表示小端
	//返回0表示大端
	return u.c;
} 
int main0904()
{
	int ret1 = check_sys1();
	if (1 == ret1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
	//。。。妙不可言。。。
}



//联合体的大小：
//联合体的大小至少是最大成员的大小 - 也就是说联合体的大小也不一定是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍的时候，最大成员就要对齐到最大对齐数的整数倍
union Un2
{
	int a;//自身大小4   默认对齐数8   较小值4
	//注意数组是算元素的对齐数  而不是总共有几个元素  这里相当于写了5个char  
	char arr[5];//char类型大小1    默认对齐数8    较小值1
	//联合体的大小一定是最大对齐数的整数倍 - 最大对齐数是4
};
int main0905(void)
{
	union Un2 u;
	printf("%d\n",sizeof(u));//8
	return 0;
}

