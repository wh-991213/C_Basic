#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main0401(void)
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	//getchar用于接收键盘的字符
	//putchar用于输出
	return 0;
}

int main0402(void)
{
	int ch = 0;
	while ((ch = getchar()) != EOF)//这里输入EOF并不会终止循环；因为getchar会先接收E并打印，再接收O并打印... ...
	{
		putchar(ch);	
	}
	//如何结束呢循环？？？
	//在控制台按(CTRL+Z)
	return 0;
}


//观察下面代码 
int main0403(void)
{
	int ret = 0;
	int ch  = 0;
	char password[20] = { 0 };
	printf("请输入密码:>"); 
	scanf("%s", password);
	printf("请确认(Y/N):>");
	//getchar();//2+
	//getchar();//2+
	//getchar();//2+
	//getchar();//2+
	//getchar();//2+
	//getchar();//1+
	while ((ch=getchar())!='\n')//3+
	{
		;
	}
	ret=getchar(); //这里ret是10对应ASCII码'\n'
	if (ret == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("放弃确认\n");
	}

	//出现的问题：
	//1.为什么getchar并没有等待接收字符？？？
	/*因为当scanf输入密码123456，并存储到对应的地址里。输入的字符中还隐藏'\n'，
	并在缓冲区中保留，所以当运行到getchar时，缓冲区里已有内容，getchar并不会停止
	同时也知道了，getchar只有缓冲区没有内容时才会等待
	*/
	/*
	解决方法：
	可以在ret=getchar()前加一个getchar()把'\n'读走
	*/

	//2.为什么输入123456 ABCD时，gechar也没有等待？？？
	/*
	因为scanf不会接收空格和换行,所以这里缓冲区里保留了' '(空格)ABCD'\n'6个字符
	解决方法：
	可以在ret=getchar()前总共加6个getchar()依次把 ' '(空格)ABCD'\n'读走
	*/

	//3.这样一直写getchar接收缓冲区里的字符过于繁琐，请使用简洁点的方法？？？
	//while循环
	return 0;
}


//观察以下代码

int main0404(void)
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch<'0' || ch>'9')
			continue;
		putchar(ch);
	}
	return 0;
}