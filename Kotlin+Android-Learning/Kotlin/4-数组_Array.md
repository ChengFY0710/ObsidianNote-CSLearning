## 01 arrayOf( )

```kotlin
package com.chengfy.firstkotlinprogram  
  
fun main(args: Array<String>) {  
  
    var age = arrayOf(1, 2, 3)  
  
    println("First = " + age[0])  
    println("Second = " + age.get(1))  
    println("Third = " + age[2])  
  
    var cars = arrayOf("BMW", "Opel")  
  
    println("------------------")  
  
    println("First = " + cars[0])  
    println("Second = " + cars[1])  
  
    cars.set(1, "Xiaomi")  
  
    println("------------------")  
  
    println("First = " + cars[0])  
    println("Second = " + cars[1])  
  
    println(cars.size)  
  
    var carsAndAge = arrayOf("Mercedes", 5, "BMW", 10)  
  
    println("-------------------")  
  
    println("First element of Array = " + carsAndAge[0])  
    println("First element of Array = " + carsAndAge.get(1))  
    println("First element of Array = " + carsAndAge[2])  
    println("First element of Array = " + carsAndAge[3])  
      
}
```

## 02 arrayListOf< >( )
```kotlin
var age = arrayListOf<Int>()
var age = ArrayList<Int>()
```

>[!tip] 两种method的区别
>`arrayListOf`方法，可以在创建数组时向数组重添加元素，而`ArrayList`方法，向数组中添加元素的前提是已经创建好了这个数组。

## 03 数组操作
### （1）增删元素
```kotlin
var age = ArrayList<Int>()
age.add(20)
age.add(index:3, element:20)
age.remove(10)
age.removeAt(index:1)
```

+ **add()方法**：可以向数组末尾增加元素，也可以向数组中插入元素。
+ **remove()方法**：可以删除数组中的元素，两种方式，其一是 `remove(elementValue)`，其二是 `removeAt(index)`。

示例：
```kotlin
package com.chengfy.firstkotlinprogram  
  
fun main(args: Array<String>) {  
  
    var age = ArrayList<Int>()  
    age.add(10)  
    age.add(1, 15)  
    age.add(20)  
    println("First element of ArrayList = " + age[0])  
    println("Second element of ArrayList = " + age.get(1))  
    println("Third element of ArrayList = " + age[2])  
  
    age.remove(15)  
    println(age.size)  
    println("First element of ArrayList = " + age[0])  
    println("Second element of ArrayList = ${age.get(1)}")  
  
    var cars = arrayListOf<String>("Opel", "BMW")  
  
    cars.add("Ford")  
  
    println("1st = " + cars[0])  
    println("2nd = " + cars.get(1))  
    println("3rd = ${cars[2]}")  
  
    var mixArray = ArrayList<Any>()  
    mixArray.add("Xiaomi")  
    mixArray.add(18)  
    mixArray.add("Fold")  
    mixArray.add(true)  
  
    println(mixArray[0])  
    println(mixArray[1])  
    println(mixArray[2])  
    println(mixArray[3])  
  
}
```
