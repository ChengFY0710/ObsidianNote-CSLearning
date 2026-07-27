getchar和putchar函数作为**单字符I/O**，**每次只处理一个字符。**其实他们不是真正的函数，而是被定义为供预处理器使用的宏。
```c
#include <stdio.h>
int main()
{
    char c;
    while((c=getchar()) != '\n')
        putchar(c);

    return 0;
}
```
getchar()通常和循环一起使用。获取用户输入的**逐个字符**。
