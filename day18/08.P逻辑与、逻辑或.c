#include<stdio.h>
//观察并判断以下代码结果
int main0601()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++&&++b&&d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//1  3  3  5 ？？？
	//相信就会有很多人会被套路到，我也是其中之一
	//因为a是后自增，所以一开始a为0为假，左边为0的话，则右边不管什么都为假。所以右边的++b和d++并没有算
	//这里的结果是1,  2,  3,  4
	//当然如果想要得到上面的这个结果的话（1  3  3  5）可以把a++改成++a,此时为真，那么后面的++b和d++就会算了
	return 0;
}

int main0602(void)
{
	int i = 0, a = 1, b = 2, c = 3, d = 4;
	i = a++ || ++b || d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//2, 3, 3, 5 ？？？
	//答案当然没有想的那么简单
	//因为a是后自增，为真。所以左边为真的话，则右边不管什么都为真，所以右边的++b和d++并没有算
	//这里的结果是2, 2, 3, 4
}