# 12 - 4 typedef工具和其他复杂声明

typedef工具是一个高级数据特性,利用typedef可以为**某一类型**自定义名称。

```c
typedef unsigned char BYTE;
BYTE x, y[10], *z;
// 相当于
unsigned char x, y[10], *z;

typedef struct {
    int year;
    int month;
    int day;
} birthday;
birthday r1, r2;
```
+ BYTE作用域取决于typedef定义所在的位置。
+ typedef是由**编译器处理**的，这与#define不同
+ 若有typedef，编译器会把BYTE解释成**变量**，若无typedef，编译器会把BYTE解释成**类型名**。

---

+ 数组名后面的``[]``和函数名后面的``()``具有**相同的优先级**。它门比``*``**(解引用运算符)**的优先级**高**。因此下面声明的risk是一个指针数组,不是指向数组的指针:
```c
int * risks [10];
```
+ ``[]``和``()``的优先级**相同**,由于都是**从左往右**结合,所以下面的声明中,在应用方括号之前,``*``先与rusks结合。因此rusks是一个**指向数组的指针**,该数组内含10个int类型的元素:
```c
int (* rusks)[10]; // 指向数组的指针
int * rusks[10];// 指针数组
```
+ ``[]``和``()``都是**从左往右**结合。因此下面声明的goods是一个由12个内含50个int类型值的数组组成的二维数组,不是一个有50个内含12个int类型值的数组组成的二维数组:
```c
int goods [12][50];
```

![12 - 4 - 1](/引用文件/12%20-%204%20-%201.png)

```c
char * fump(int);  //函数
char (* frump)(int); //指向返回值为char类型，接收参数为int类型的函数的指针
char (* frump[5])(int); //指向返回值为char类型，接收参数为int类型的函数的指针数组
```

