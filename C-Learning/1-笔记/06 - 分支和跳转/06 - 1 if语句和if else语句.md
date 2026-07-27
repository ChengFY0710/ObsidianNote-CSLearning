```c
if(exp)
    *statement*
```
以上是if语句的基本结构。if语句被称为**分支语句**或**选择语句**。

---

## 01 if else 语句
if（表达式）
else 
else后即不满足if后表达式的情况。
## 02 else if 语句
```c
#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  int a;
      scanf("%d",&a);
      if(a>=90 && a<=100)
      printf("A");
      else if(a>=80 && a<90)
      printf("B");
      else if(a>=70 && a<80)
      printf("C");
	  else if(a>=60 && a<70)
      printf("D");
      else if(a<60 && a>=0)
      printf("E");
      else
      printf("Score is error!");
	  /*********End**********/ 
       return 0;
	}
```
else if语句会**从上至下**依次判断，当判断其中有一为真时，便**停止**对下面的判断。
>[!tip]
>若使用多次if，则计算机会进行多次判断，会影响运行效率。

## 03 else与if配对
else总是会**与其上最近的if语句配对**。语句分复合语句和一条简单语句。
