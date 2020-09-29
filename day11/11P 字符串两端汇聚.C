#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>


//welcome to aoligei!!!!
//######################
//w####################!
//we##################!!
//wel################!!!
//... ...
//welcome to aoligei!!!!
int main1101()
{
	char arr1[] = "welcome to aoligei!!!!";
	char arr2[] = "######################";
	int left = 0;//左下标
	//int right = sizeof(arr1) / sizeof(arr1[0])-1;//err；这样得到的是'\0'的下标22；如果非要这样写就要减2
	int right = strlen(arr1)-1;//右下标

	while(left<=right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		//休息1秒,单位毫秒；Sleep所在头文件<windows.h>
		Sleep(1000);
		//system执行系统命令的一个函数，所在头文件<stdlib.h>；cls是清空屏幕
		system("cls");
		left++;
		right--;
	}
	printf("%s\n", arr2);//因为上面的内容已全部清空，在这加上内容
	
	return 0;
}