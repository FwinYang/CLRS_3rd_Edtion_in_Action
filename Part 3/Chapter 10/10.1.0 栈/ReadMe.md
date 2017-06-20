栈（数据结构）
=========

数据结构描述
----------------

栈是一个动态集合，且在其上进行的DELETE操作所移除的元素是预先设定的，

在栈（stack）中，被删除的元素总是最近插入到栈里的元素，

栈实现的是一种**后进先出**（LIFO）的策略。

栈的INSERT操作被称为“压入”（PUSH），而无参数的DELETE操作被称为弹出（POP），

这里我们用普通的不可变长数组，比如S[1..n]，来实现一个最大能容纳n个元素的栈。

这个数组有一个属性S.top，指向最新插入的元素，栈中包含的元素包括S[1..top]，

其中S[1]叫做栈底元素，S[S.top]叫做栈顶元素。

当S.top等于0时，栈中不包含任何元素，即栈是空的，要测试一个栈是否为空可以用查询操作STACK-EMPTY(S)。

如果试图对一个空栈进行弹出操作，会发生栈下溢（Stack Underflow），

如果S.top超过n，就会发生栈上溢（[Stack Overflow](www.stackoverflow.com)）。

通常这个数据结构支持的基础操作
----------------------------------

1. 判断栈S是否为空。
2. 入栈。
3. 出栈。

算法伪代码
-----------

```
//判断栈S是否为空。
STACK-EMPTY(S)
	if S.top == 0
		return true
	else return false
```

```
//把元素x压入栈S中。不检查会不会栈上溢。
PUSH(S, x)
	S.top = S.top + 1
	S[S.top] = x
	
//出栈，检查栈下溢。
POP(S)
	if STACK-EMPTY(S)
		error "underflow"
	else S.top = S.top -1
	return S[S.top + 1]
```