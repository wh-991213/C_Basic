#include<stdio.h>
#include<string.h>

int main0101()
{
	//char类型数组存储字符串
	//'a', 'b', 'c', '\0'
	char arr1[] = "abc";
	printf("%s\n", arr1);//abc
	printf("%d\n", sizeof(arr1));//4
	//strlen==string+length  所在头文件<string.h>,它可以计算字符串长度，并不包括'\0'
	printf("%d\n\n", strlen(arr1));//3

	//'a','b','c'
	char arr2[] = { 'a','b','c' };
	printf("%s\n", arr2); //abc烫烫烫烫蘟bc
	printf("%d\n", sizeof(arr2));//3
	//通过这个答案，我们可以知道它在15个字符之后遇到了'\0'
	printf("%d\n\n", strlen(arr2));//15(随机值)


	//接着我们在arr2后添加一个0或 '\0'
	char arr3[] = { 'a','b','c',0};
	printf("%s\n", arr3);//abc
	printf("%d\n", sizeof(arr3));//4
	printf("%d\n", strlen(arr3));//3


	//由此可得出'\0'或0是字符串的结束标志；'\0'也是一个字符，它的值是0
	//字符串的结束标志是一个'\0'的转义字符，在计算字符串长度的时候'\0'是结束标志，不算作字符串内容

	return 0;
}

	//我们知道计算机中存储的是2进制，那a、A、#、这些字母符号怎么存呢？
	//给这些字符编值？
	//a--97
	//A--65
	//...	
	//给每个字符都编一个值，这种标准叫做ASCII编码(美国信息交换标准代码)；这个字符所对应的值叫ASCII码值

int main0102(void)
{
	//转义字符
	printf("abc\n");

	//打印一个路径
	//这里\t是水平制表符，相当于一个Tab
	printf("c:\test\32\test.c\n");

	//那我们就想要打印这段路径呢？？
	//加上一个\，防止它被解释为一个转义序列符
	printf("c:\\test\\32\\test.c\n");

	//编译器会将前面两个单引号解析成括字符的那一对单引号，后面的一个单引号就落单了
	//在前面加上个\使它转义
	printf("%c\n",'\'\n');

	//\ddd表示1-3个八进制数字
	//\32：32是两个8进制数字,它是一个转义字符
	//32作为8进制代表的那个十进制数字，作为ASCII码值，对应的字符
	//8进制32对应10进制26作为ASCII码代表的字符是—>
	printf("%d\n",strlen("c:\test\32\test.c"));//13
	printf("%c\n", '\32');

	//\xdd:dd表示2个16进制数字
	//16进制x61对应10进制97
	printf("%c\n", '\x61');//a
	return 0;
}

