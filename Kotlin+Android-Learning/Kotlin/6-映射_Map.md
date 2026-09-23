
## 01 定义
![[引用文件/Kotlin+Android-Learning/K-6-1.png|535]]
```kotlin
fun main(args: Array<String>) {  
  
    var age = mapOf<String, Int>("David" to 20, "Ronaldo" to 25)  
  
    println("age of David : " + age["David"])  
    println("age of Ronaldo : " + age["Ronaldo"])  
  
}
```

>[!warning]
>mapOf( ) 是 immutable 方法，元素必须在定义时指定，后续不可更改。
>mutableMapOf( ) 是 mutable 方法，元素后续可以改变。

## 02 mutableMapOf()
后续可追加元素
### put()方法
```kotlin
package com.chengfy.firstkotlinprogram  
  
fun main(args: Array<String>) {  
  
    var age = mapOf<String, Int>("David" to 20, "Ronaldo" to 25)  
  
    println("age of David : " + age["David"])  
    println("age of Ronaldo : " + age["Ronaldo"])  
  
    var mutableage = mutableMapOf<String, Int>("David" to 20, "Ronaldo" to 25)  
  
    mutableage.put("Buffon", 30)  
  
    println("age of David : " + mutableage["David"])  
    println("age of Ronaldo : " + mutableage["Ronaldo"])  
    println("age of Buffon : " + mutableage["Buffon"])  
  
}
```
