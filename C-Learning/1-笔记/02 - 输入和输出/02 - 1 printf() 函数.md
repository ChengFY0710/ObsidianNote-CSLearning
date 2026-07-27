
printf()函数和scanf()函数用第一个参数表明后面有多少参数。

---
## 00 概念
```c
printf("My name is %s.","MIKE");
```
**参数**："My name is %s." 为第一个参数，以此类推第二个参数...printf()输出以第一个参数为主。
**转换说明**：%s 等，将第二、三....个参数引入第一个参数中。第一个参数表明后面==**依次引入**==多少个参数。
![02 - 1 - 1.png](/引用文件/02%20-%201%20-%201.png)
>[!tip]
>打印%，只需输入两个%

**转换说明**：在==%和转换字符间==可以插入修饰符，修饰基本的转换说明。
![02 - 1 - 2.png](/引用文件/02%20-%201%20-%202.png)
![02 - 1 - 3.png](/引用文件/02%20-%201%20-%203.png)

---
## 01 输出字符串
### （1）直接输出
```c
#include <stdio.h>
int main()
{
	printf("Xiaomi HyperOS 3""Xiaomi HyperCore");
	return 0;
}
```
此时输出的结果是 Xiaomi HyperOS 3Xiaomi HyperCore 
不管两字符串中间有没有空格，输出结果都是无空格的。
>[!warning]
>注意：若多字符串中有逗号，==**输出到逗号处即停止**==。
### （2）"%s"
```c
#include <stdio.h>
int main()
{
	char name[40];
	printf("What is your name?");
	scanf("%s",name);
	printf("Hello,%s",name);
	
	return 0;
}
```

## 02 输出 int 型整数
### （1）十进制输出 "%d"
[[02 - 2 scanf() 函数#==01 读取整数 "%d"==|"%d"]] 表示后面有一个整数输出在"%d"所在的位置上，==**实际上输出的都是字符串**==。
```c
#include <stdio.h>
int main()
{
	printf("%d",12+34);
	return 0;
}
```
输出结果：46
```c
#include <stdio.h>
int main()
{
	printf("输出数字：%d",12+34);
	return 0;
}
```
输出结果：输出数字：46
>[!tip]
>%d 相当于是一个占位，展示后面的数字或计算结果。

>[!warning]
>==**⚠️注意：C语言不允许直接输出printf(a+b)**==

### （2）八进制输出 "%o"
```c
int x = 100;
printf("%o",x);
```
最终结果会以八进制的形式输出。
>[!tip]
>若要输出八进制前加上八进制前缀 0 ，则需使用"%#o"
>```c
>printf("%#o",x);
>```
>输出**0**1234567

### （3）十六进制输出 "%x"
```c
int x = 100;
printf("%x",x);
```
最终结果会以十六进制的形式输出。
>[!tip]
>若要输出十六进制前加上十六进制前缀 0x ，则需使用"%#x"
>```c
>printf("%#x",x);
>```
>输出**0x**1234567

## 03 输出浮点数 "%f"
[[03 - 1 变量#==03 变量类型==#浮点数|什么是浮点数]]
```c
float a = 3.14;
double b = 3.1415926535;
printf("%f\n",a);
printf("%f",b);
```
此时输出：
	`3.140000`
	`3.141593`
>[!note]
>printf()函数默认输出浮点数是==**六位小数**==，超出则**四舍五入**，不足则**补0**。
>同时，float类型在printf()函数中会**升为double类型**。

---

## 注意事项
### （1）转换不匹配
```c
float n1 = 3.14;
double n2 = 3.1415926535;
long int n3 = 1222222,n4 = 5555555;
printf("%ld %ld %ld %ld",n1,n2,n3,n4);
```
printf()函数中转换说明应与后面的参数在**数据类型**上统一。若不一致，则会出现错误。
### （2）printf()函数的返回值
printf()函数的返回值是其==**打印字符的个数**==。通常很少用到。
```c
int a;
a = printf("Xiaomi HyperOS.");
printf("%d",a);
```
>[!warning]
>printf()函数的返回值，包括==**空格和不可见的换行符\n**==。
### （3）打印较长的字符串
>[!warning] 
>注意，当打印的字符串太长需要换行时，不能在参数的引号中间换行，可以在参数逗号前后换行。

为方便阅读，写代码时可以采用以下方法换行，但并不会对打印内容有影响。
+ **方法一**：使用\
```c
	a = printf("Xiaomi HyperOS is the be\
st operating system for mobile phone.");
	printf("%d",a);")
```
注意：\断开后，第二行必须顶格写，否则空格会算入打印的内容中。‘
+ **方法二**：ANSI C引入的双“”“”
```c
	int a;
	a = printf("Xiaomi HyperOS is the"
	" best operating system for mobile phone.");
	printf("%d",a);
```
