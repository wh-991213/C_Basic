#include<stdio.h>

//enum：枚举关键字；Day是我们定义的枚举类型名；enum Day：枚举类型；
enum Day
{
	//{}里放的是枚举的可能取值 - 这里面的可能取值是枚举常量
	//枚举里面可能取值的类型不是我们自己定义的 - Mon、Tues、Web、、、并没有指定类型 - 规定枚举里的可能取值都是一个整型的值 - 所以不能左右枚举可能取值里的类型
	Mon,
	Tues,
	Web,
	Thur,
	Fri,
	Sat,
	Sun
};
enum Color
{
	//上面说到枚举里面的可能取值是枚举常量 - 默认值0，1，2 - 下面已打印
	RED,//0  
	GREEN,//1
	BLUE//2
};
enum Sex
{
	//修改枚举里可能取值的默认值 - 0，1，2
	//常量 - 我们都知道常量的值是不能修改的
	//这里不是改，而是赋一个初始值，也就是说这个常量本没有值；当确定了这个值时，后面才不能更改；如果不赋初始值的话，它才会默认0，1，2
	MALE=2,	
	FEMALE=4,
	SECRET=8,
};
enum Fruit
{
	//那如果是这样呢
	//在默认情况下是0,1,2；如果只赋值第一个常量，后面的值就以第一个值自增；如果只赋值第二个常量，那么第一个值还是默认值0，以第三个常量开始自增
	APPLE,
	PEAR=2,
	ORANGE,	
};
int main0701()
{
	//有了枚举类型，定义枚举变量，进行赋值（只能用括号里的值赋值）
	//枚举类型+变量=枚举成员
	//enum Color c= BLUE;
	//enum Sex s = MALE;
	

	//还有个问题 - 使用枚举可能取值来赋值or使用枚举可能取值的常量值来赋值
	enum Fruit d = PEAR;//这里ok的
	//enum Fruit d = 2;//err - 2是int类型||d是枚举类型的 - 虽然在VS2017中没有报错 - 但不报错不代表它是完全正确的；如果换成c++ - err:无法从int转换为Fruit

	printf("%d %d %d\n", RED, GREEN, BLUE);//0,1,2
	printf("%d %d %d\n", MALE,FEMALE,SECRET);//2,4,8
	printf("%d %d %d\n", APPLE, PEAR, ORANGE);//0,2,3
	return 0;
}