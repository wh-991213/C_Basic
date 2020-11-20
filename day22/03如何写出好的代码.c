#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//优秀的代码：
//1.代码运行正常
//2.bug少
//3.效率高
//4.可读性高
//5.可维护性高
//6.注释清晰
//7.文档齐全

//常见的coding技巧
//1.使用assert
//2.尽量使用const
//3.养成良好的编码风格
//4.添加必要的注释
//5.避免编码的陷阱



//示范：模拟实现库函数:strcpy - 字符串拷贝
int main0301()
{
	//这里先使用库函数将arr2里的内容拷贝到arr1中去
	char arr1[] = "**************";
	char arr2[] = "hello";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	//为什么把arr2拷贝到arr1里并没有打印后面的*号？？？ - 这里拷贝完成后其实arr1后面是有*号的，没有打印*号的原因是因为在拷贝的时候也把hello后面的\0也拷贝过去了

	return 0;
}

 
void my_strcpy(char* dest, char* src)
{
	while (*src!='\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;//这里是为了把'\0'也拷贝进去 - 这种方式挺戳
}
//第一个版本 - 6分
int main0302(void)
{
	//模拟实现strcpy
	char arr1[] = "**************";
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


void my_strcpy1(char* dest, char* src)
{
	while (*dest++ = *src++)//借助了'\0'的ASCII码让循环停止
	{
		;
	}
}
//第二个版本 - 7分
int main0303(void)
{
	char arr1[] = "**************";
	char arr2[] = "hello";
	my_strcpy1(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



void my_strcpy2(char* dest, char* src)
{
	//当我们使用指针时需要判断指针的有效性 - 在使用指针时不管三七二十一就使用是有问题的
	//如果有一个指针是空指针，虽然什么也没干，但程序也不致于崩溃 - 不干就不干，但不能搞破坏
	//但是如果进行这样的一个判断 - 这个程序本身是有问题的，运行后，它什么也没干。 - 它好像是把这个问题规避掉了 - 就是不容易发现问题所在 
	//解决方法：当这个参数传错了，应该及时的让我找到这个问题
	if (dest != NULL && src != NULL)
	{
		while (*dest++ = *src++)
		{
			;
		}
	}

}

int main0304(void)
{
	char arr1[] = "**************";
	char arr2[] = "hello";
	my_strcpy2(arr1, NULL);//假设这里传错了参数
	printf("%s\n", arr1);
	return 0;
}


void my_strcpy3(char* dest, char* src)
{
	assert(dest!=NULL);//断言；assert这个函数所在头文件是<assert.h> - 如果括号里的表达式为真就什么也不做 - 如果括号里的表达式为假就会报错 - 这里传过来的参数不是空指针为真则不执行；如果传过来的参数是空指针为假就会报错
	assert(src != NULL);//如果用assert去解决问题时，发现问题时，它会把问题抛出来
	while (*dest++ = *src++)
	{
		;
	}
}
//第三个版本 - 8分
int main0305(void)
{
	char arr1[] = "**************";
	char arr2[] = "hello";
	my_strcpy3(arr1, NULL);
	printf("%s ", arr1);
	return 0;
}

 
void my_strcpy4(char* dest, char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*src++ = *dest++)//假设这里写错了，下面的dest和src也对应，有可能问题出在哪也不知道 - 如果在每二个参数上加上const，就能很有效的发现问题所在 
	{
		;
	}
}
//第四个版本 - 错误演示版
//再来看下strcpy函数的参数 - char* strcpy(char* strDestination,const char* strSource) - 第二个参数是const
int main0306(void)
{
	char arr1[] = "*****";
	char arr2[] = "hello";
	my_strcpy4(arr1, arr2);
	printf("%s ", arr1);
	return 0;
}


void my_strcpy5(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}
//第五个版本 - 9分
int main0307(void)
{
	char arr1[] = "*****";
	char arr2[] = "hello";
	my_strcpy5(arr1, arr2);
	printf("%s ", arr1);
	return 0;
}
 

//对于const
int main0308(void)
{
	//int num = 10;//可以修改其值
	//const int num = 10;//如果使用const修饰num，则不能修改 - 但如果把num的地址交给指针，则就可以利用指针修改 - int* p=&num;*p=20
	//num = 20;
	

	const int num = 10;
	const int* const p = &num;//const还可以放在右边，它们代表的意义不同 - const放在*号的左边时，修饰的是*p,表示不能通过p来改变*p(num)的值 - const放在*号的右边时，修饰的是指针变量p,表示不能修改指针指向的地址
	//*p = 20;//err - num的地址已经被限制成常量了

	printf("%d\n", num);
	return 0;
}


char* my_strcpy6(char* dest, const char* src)//char* strcpy(char* strDestination,const char* strSource) - 这个函数的功能是要把原字符串拷贝到目标里去 - 这里拷贝完后把目标的地址返回
{
	char* ret = dest;//预先保留一份dest起始位置的地址 - 用于返回
	assert(dest != NULL);//保证指针的有效性
	assert(src != NULL);
	//把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
//第六个版本 -  会将必要的注释写上(不计分) - 10分
int main0309(void)
{
	char arr1[] = "************";
	char arr2[] = "hello";
	printf("%s ", my_strcpy6(arr1, arr2));//拷贝完之后，返回目标地址 - 直接放进去打印
	//最后这个代码对比之前的代码：
	//1.让字符串的自增和拷贝以及'\0'的拷贝放在了while循环的判断条件里
	//2.使用了assert
	//3.使用了const
	//4.函数的返回类型设计成了char*
	return 0;
}



int my_strlen(const char* str)
{
	int count = 0;//计数器
	assert(str != NULL);//保证指针的有效性
	while (*str++)
	{
		count++;
	}
	return count;
}
//模拟实现strlen函数 - 满分
int main0310()
{
	char arr[] = "abcdef";
	printf("%d\n",  my_strlen(arr));
	return 0;
}

//编程常见错误
//1.编译型错误：直接看到错误提示信息 - 相对来说简单
//2.链接型错误：比如所使用的函数没有导入头文件所报的错误 - 无法解析外部符号；  这种错误的产生：要么就是该函数未定义，要么就是函数名写错了
//3.运行时错误：编译型与链接型错误对比运行时错误，那都不叫错误  - 运行时错误：结果与预期不符  解决方法：借助调试，逐步定位问题
//对于上述的错误：平时应该积累排错的经验