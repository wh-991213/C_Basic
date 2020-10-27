
int main0301()
{
	int arr[10] = { 0 };
	//观察A、B、C
	//A
	printf("%p\n", arr);//00EFF8E0
	printf("%p\n", arr+1);//00EEF8E4

	//B
	printf("%p\n", &arr[0]);//00EFF8E0
	printf("%p\n", &arr[0]+1);//00EFF8E4

	//C
	printf("%p\n", &arr);//00EFF8E0
	printf("%p\n", &arr+1);//00EFF908
	//发现A和B都是跳过一个整型的元素，而C是跳过一整个数组
	//所以arr和&arr[0]是首元素地址；而&arr是整个数组的地址
	//在绝大多数情况下数组名都是首元素地址；有两个例外：
	//1.&arr - &数组名 - 数组名不是首元素地址 - 数组名表示整个数组，取出的是整个数组的地址
	//2.sizeof(arr) - sizeof(数组名) - 数组名表示整个数组 - sizeof(数组名)计算的是整个数组的大小，单位是字节
	return 0;
}

int main0302(void)
{
	int arr[10] = { 0 };
	int* p = arr;
	//此时arr数组就可以通过指针很好的访问
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (int i = 0; i < 10; i++)
	{
		//printf("%d ", arr[i]);//数组的方式
		printf("%d ", *(p + i));//指针的方式
	}
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%p   ===   %p\n",p+i, &arr[i]);
	//	结果是一样的
	//}
	return 0;
}

int main0303(void)
{
	int a = 10;
	int* pa = &a;//pa就是一级指针变量，int*就是一级指针类型
	//上面说到pa是变量，那么它也需要在内存中开辟空间,如果要取它的地址，需要用二级指针存储
	int** ppa = &pa;//ppa就是二级指针变量，int**就是二级指针类型
	//同理
	int*** pppa = &ppa;//三级指针
	//如果要打印a,假设只用ppa
	printf("%d\n", **ppa);
	return 0;
}

int main0304(void)
{
	//指针数组 - 数组 - 存放指针的数组 
	int a = 10;
	int b = 20;
	int c = 30;
	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	//... ...	
	//比较麻烦，能不能像数组一样
	//整型数组 - 存放整型
	//字符数组 - 存放字符
	//指针数组 - 存放指针
	int* arr[3] = {&a , &b , &c};//这里就是一个指针数组
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", *(arr[i]));
	}
	//数组指针 - 指针
	return 0;
}