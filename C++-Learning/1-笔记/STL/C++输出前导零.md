两种主流写法：
## 1. cout + setw + setfill（需 `<iomanip>`）

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

cout << setfill('0') << setw(5) << 123 << endl;   // 00123
cout << setfill('0') << setw(5) << 1 << endl;     // 00001
cout << setfill('0') << setw(5) << 99999 << endl; // 99999（够宽不补）
```

**注意**：

- `setw` 只对**紧接的下一个输出**生效，用完即失效；`setfill` 是持久的。
- 位数超过宽度时**不截断**，原样输出。
- 负号占一位：`setw(5) << -1` 输出 `000-1`，不是 `-0001`。所以链表题里 `-1` 要单独处理（上一轮代码里就是特判输出 `"-1"`）。

## 2. printf（需 `<cstdio>`）

```cpp
printf("%05d\n", 123);   // 00123
printf("%05d\n", 99999); // 99999
printf("%05d\n", -1);    // 000-1，同样要特判
```

`%05d` 表示：`0` 补零、`5` 最小宽度、`d` 十进制整数。

## 对比

|场景|推荐|
|---|---|
|普通 C++ 输出、一次性补零|`setw` + `setfill`|
|多次/批量、习惯 C 风格|`printf("%05d")`|

链表题里输出 5 位地址，两种都可以，只要记住：**`-1` 永远单独输出 `"-1"`**。

