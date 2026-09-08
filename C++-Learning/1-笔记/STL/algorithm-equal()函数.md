C++算法equal函数比较**两个容器**的元素，如果找到两个容器的所有元素，则返回**true**值。
## 01 函数原型
```cpp
template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2 );
```
+ `[first1, last1)`：第一个待比较区间
- `first2`：第二个区间起始迭代器，**没有结束迭代器**，默认长度和第一个区间一样
- 返回：`true` 两个区间所有元素对应相等；`false` 不相等
>[!warning]
>⚠️重要坑：这个重载**不会检查第二个容器的大小**！如果第二个容器比第一个短，会越界访问，未定义行为！

>[!tip]
>C++14新增**带第二个区间的结束迭代器**，会先比较两个区间长度，长度不一样直接返回false，不会越界。

