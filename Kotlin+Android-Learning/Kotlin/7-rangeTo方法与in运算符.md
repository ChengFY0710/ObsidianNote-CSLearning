```kotlin
package com.chengfy.firstkotlinprogram  
  
fun main(args: Array<String>) {  
    var myCharRange = 'a'.rangeTo('j')  
    var myChar = 'k' in myCharRange  
    println("myCharRange has k : " + myChar)  
  
    var myCharRange2 = 'a'..'z'  
    myChar = 'k' in myCharRange2  
    println("myCharRange2 has k : " + myChar)  
  
}
```
