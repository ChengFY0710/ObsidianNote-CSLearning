## 01 link 标签
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" type="text/css" href="sheet1.css" media="all">
</head>
<body>

</body>
</html>
```
link标签的基本作用是**把其他文档与当前文档关联起来**。CSS使用它链接应用到文档上的样式表。
上述文档链接了一个名为 sheet1.css 的样式表。
+ **外部样式表（external stylesheet）**：通过link标签链接的样式表。

>[!tip]
>link标签必须放在head元素中。

### 属性
+ **rel**：表示引用文档与本文档间的关系，这里是 **stylesheet** 。
+ **type**：始终为 **text/css**，说明**通过link标签**加载的数据类型。这样Web浏览器才知道加载的样式表是CSS样式表。
+ **href**：它的值是样式表的URL，可以是**绝对地址**，也可以是**相对地址**。
+ **media**：它的值是一个或多个**媒体描述符（media descriptor）**，指明媒体的类型和具有的功能。多个媒体描述以逗号分开。

>[!tip]
>一个文档可以关联多个样式表，具体可以如下操作：
>```html
><link rel="stylesheet" type="text/css" href="basic.css">
><link rel="stylesheet" type="text/css" href="splash.css">
>```
>这样，浏览器会加载制定的两个样式表，合并样式规则后再应用到文档上。

### 候选样式表
+ **候选样式表（alternate stylesheet）**：定义方式为把rel属性设为 alternate stylesheet。**仅当用户自己选择，文档才会使用候选样式表渲染**。
候选样式表可以使用 link 元素 title 属性，设定不同的值，方便用户选择。
```html
<link rel="altenate stylesheet" type="text/css" href="sheet1.css" title="Default" media="screen">
```

>[!faq]- 可以多个首选样式表叠加title属性吗？
>一个文档可以关联多个样式表，具体可以如下操作：
>```html
><link rel="stylesheet" type="text/css" href="basic.css">
><link rel="stylesheet" type="text/css" href="splash.css">
>```
>这样，浏览器会加载制定的两个样式表，合并样式规则后再应用到文档上。
>但如果都加上title属性后，**只会使用其中一个，两外两个完全忽略，且无法确定忽略的是哪些**。

## 02 style 元素
style元素也是一种引入样式表的方式，直接写在文档中：
```html
<style type="text/css">...</style>
```

>开始和结束style标签之间的样式称为**文档样式表(documentstylesheet)** 或**嵌入式样式表(embeddedstylesheet**,因为这种样式表**内嵌在文档中**)。style元素可以直接包含应用到文档上的样式,也可以通过@import指令引入外部样式表。

即内嵌在文档中的样式表，在head标签内。
## 03 @import 指令
```html
<style type="text/css">
@import url(styles.css);/*@import放在开头*/
h1 {color: gray;}
</style>
```

与link一样，Web浏览器遇到@import指令时**会加载外部样式表**，使用其中的样式渲染HTML文档。二者之间唯一的主要区别在于句法和指令的立置。可以看出，**@import指令在style元素内部,而且必须放在其他CSS规则前面,否则不会起作用。**
与link一样，一个文档内可以有多个@import语句，然而不同的是，@import 指令的导入的**每个样式表都会使用**，无法指定候选样式表。
```html
<style type="text/css">
@import url(sheet2.css)
@import url(blueworld.css)
@immport url(zany.css)
</style>
```
与link类似,@import指令也可以显示导人的样式表应用于何种媒体。方法是在样式表的URL后面提供媒体描述符:
```html
<style type="text/css">
@import url(sheet2.css) all;
@import url(blueworld.css) screen;
@import url(zany.css) projection, print;
</style>
```

>[!tip]- @import 指令有什么用？
>如果一个外部样式表需要用到**另一个外部样式表**中的样式，@import指令的作用就体现出来了。外部样式表**不能包含**任何文档标记，也就是**不能使用link元素**，但是可以使用@import指令。外部样式表中可能包含下述内容:
>```css
>@import url(http://example.org/library/layout.css);
@import url(basic-text.css);
@import url(printer.css)print;
body {color: red;}
h1 {color: blue;}
>```

## 04 行内样式
如果只想为**单个元素**提供少量样式，可以使用HTML元素的 **style属性** 设置行内样式。
```html
<p style="color: grey;">This is just a test.</p>
```
除了 body 元素之外的标签，所有HTML标签都能设定style属性。


