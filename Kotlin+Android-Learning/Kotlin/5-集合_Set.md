```kotlin
package com.chengfy.firstkotlinprogram  
  
fun main(args: Array<String>) {  
    /*  
    var mySetArray = arrayListOf<Any>("Kotlin", 2, 5, 'K', true, "Kotlin")  
    println(mySetArray.size)    println(mySetArray.last())    */    var mySetArray = setOf<Any>("Kotlin", 2, 5, 'K', true, "Kotlin")  
  
    println(mySetArray.size)  
    println(mySetArray.last())  
      
}
```

集合与数组类似，但不同的是，集合重的元素只能出现一次，若重复定义，则只会保留一份。
