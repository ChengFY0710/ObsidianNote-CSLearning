## 01 具体格式
声明vector二维数组格式：
```cpp
vector<vector<int>> table(size1, vector<int>(size2, 0));
```
**_代码说明：声明一个名为 table 的容器，其元素为 vector的容器。简单来说类似一个int型的二维数组。_**
![image](引用文件/C++-Learning/待定-1.png)
## 02 空间理解
在创造二维数组时，有时会出现创造失败的情况，如：
>[!error]
>
>```cpp
>vector<vector<int>> nums;
>nums[0].pushback(1);
>cout << nums[0][0];
>```

**错误原因：** 
1. 尝试访问 a 的第一个元素（即空向量），然后在其上调用push_back()方法，但是**a目前为空，没有索引为 0 的元素，因此这将导致访问越界错误。**
2.  试图输出 a 的第一个元素的第一个元素，但是由于a为空，这也会导致访问越界错误。

>[!success]
>```cpp
>vector<vector<int>> nums;
>nums.pushback(vector<int>());
>nums[0].pushback(1);
>cout << nums[0][0];
>```

## 03 二维数组的初始化
>在开始之前，有必要了解一下二维数组的行、列数如何获取。
```cpp
vector<vector<int>> nums(size1, vector<int>(size2, 0));
int row = nums.size(); //获取行数
int column = a[0].size(); // 获取列数
```
### （1）定义时直接初始化
```cpp
vector<vector<int>> nums(size1, vector<int>(size2));
vector<vector<int>> nums(size1, vector<int>(size2, 0));
```
### （2）resize构建
```cpp
vector<vector<int>> nums(size1);
for(int i=0; i<size1; i++){
	nums[i].resize(size2);
}
```
### （3）逐行操作
```cpp
vecotr<vector<int>> nums[size1];
nums[0].pushback(1);
......
```






