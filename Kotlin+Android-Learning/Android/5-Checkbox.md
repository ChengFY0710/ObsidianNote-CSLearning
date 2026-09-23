```kotlin
@Composable  
fun Checkbox(name: String, modifier: Modifier = Modifier) {  
  
    val checkboxstate = remember {  
        mutableStateOf(false)  
    }  
  
    val checkbox2state = remember {  
        mutableStateOf(false)  
    }  
  
    Column(  
        modifier = Modifier  
            .fillMaxSize()  
            .background(Color(0xFFF2F4F6)),  
        verticalArrangement = Arrangement.Center,  
        horizontalAlignment = Alignment.CenterHorizontally  
    ) {  
  
        Text(  
            text = "What is your gender?",  
            modifier = Modifier  
                .width(300.dp)  
                .clip(RoundedCornerShape(100))  
                .background(Color(0xFFFFFFFF))  
                .padding(top = 20.dp, bottom = 20.dp),  
            fontSize = 25.sp,  
            textAlign = TextAlign.Center,  
        )  
  
        Spacer(modifier = Modifier.size(20.dp))  
  
        Column(modifier = Modifier.width(300.dp)) {  
            Row(  
                verticalAlignment = Alignment.CenterVertically,  
                modifier = Modifier  
                    .clip(RoundedCornerShape(100))  
                    .width(150.dp)  
                    .background(color = Color(0xFFFFFFFF))  
  
            ) {  
                Checkbox(  
                    checked = checkboxstate.value, onCheckedChange = {  
                        if (checkbox2state.value) {  
                            checkbox2state.value = false  
                        }  
                        checkboxstate.value = it  
                    },  
                    colors = CheckboxDefaults.colors(Color(0xFF0077FF))  
                )  
  
                Spacer(modifier = Modifier.size(5.dp))  
  
                Text(text = "Male", fontSize = 20.sp)  
            }  
  
            Spacer(modifier = Modifier.size(20.dp))  
  
            Row(  
                verticalAlignment = Alignment.CenterVertically,  
                modifier = Modifier  
                    .clip(RoundedCornerShape(100))  
                    .width(150.dp)  
                    .background(color = Color(0xFFFFFFFF))  
            ) {  
                Checkbox(  
                    checked = checkbox2state.value, onCheckedChange = {  
                        checkbox2state.value = it  
                        if (checkboxstate.value) {  
                            checkboxstate.value = false  
                        }  
                    },  
                    colors = CheckboxDefaults.colors(Color(0xFF0077FF))  
                )  
  
                Spacer(modifier = Modifier.size(5.dp))  
  
                Text(text = "Female", fontSize = 20.sp)  
            }  
        }    }}
```
