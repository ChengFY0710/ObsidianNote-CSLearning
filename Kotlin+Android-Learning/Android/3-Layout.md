## 01 What is Layout
Layout is an interface that we use to **place android components(组件) on the android application**. We can use it to establish components **in a paticular order**.

## 02 Category
![[引用文件/Kotlin+Android-Learning/A-3-1.png|626]]
```kotlin
@Composable  
fun Greeting(name: String, modifier: Modifier = Modifier) {  
    Column {  
        Box(modifier = Modifier  
            .background(colorResource(R.color.grey))  
            .size(200.dp, 300.dp)  
        ){  
            Row {  
                Box(modifier = Modifier  
                    .size(50.dp)  
                    .background(colorResource(R.color.teal_200))  
                )  
                Column {  
                    Text(text = "Hello ")  
                    Text(text = "$name!")  
                }  
            }  
        }    }}
```
![[引用文件/Kotlin+Android-Learning/A-3-2.png|258]]
## 03 Arrangements and Alignments
```kotlin
@Composable  
fun MyLayouts(name: String, modifier: Modifier = Modifier) {  
  
    Column(modifier = Modifier  
        .background(colorResource(R.color.grey))  
        .fillMaxSize(),  
        verticalArrangement = Arrangement.Center,  
        horizontalAlignment = Alignment.CenterHorizontally  
    ) {  
  
        Text(text = "Hello",  
            color = colorResource(R.color.black),  
            fontSize = 24.sp,  
            fontWeight = FontWeight.Bold,  
            fontStyle = FontStyle.Italic,  
            textAlign = TextAlign.Center,  
            modifier = Modifier.background(colorResource(R.color.white))  
                .padding(start = 20.dp, end = 30.dp)  
        )  
  
        Spacer(modifier = Modifier.size(20.dp))  
  
        Text(text = "Android",  
            color = colorResource(R.color.black),  
            fontSize = 24.sp,  
            fontWeight = FontWeight.Bold,  
            fontStyle = FontStyle.Italic,  
            textAlign = TextAlign.Center,  
            modifier = Modifier.background(colorResource(R.color.white)).width(100.dp)  
        )  
  
        Spacer(modifier = Modifier.size(20.dp))  
  
        Text(text = "Kotlin",  
            color = colorResource(R.color.black),  
            fontSize = 24.sp,  
            fontWeight = FontWeight.Bold,  
            fontStyle = FontStyle.Italic,  
            textAlign = TextAlign.Center,  
            modifier = Modifier.background(colorResource(R.color.white)).width(100.dp)  
        )  
  
    }  
  
}
```
![[引用文件/Kotlin+Android-Learning/A-3-3.png|232]]