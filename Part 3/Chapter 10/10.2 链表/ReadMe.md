链表（数据结构）
==========

数据结构描述
--------------

链表（linked list）是这样的一种数据结构，其中各个对象按线性顺序排列，

而且其线性顺序是指针决定的，它为动态集合提供了灵活的表示方法。

双向链表的每个元素里都有指向前一个元素的指针prev（单向链表没有p）和指向后一个元素的指针next，

此外还有头（head）和尾（tail），循环链表的尾元素指向首元素，其他形式的链表尾元素指向NIL。

可以看出，链表可以有很多种不同的形式。

通常这个数据结构支持的基础操作
----------------------------------

1. 搜索。
2. 插入。
3. 删除。

算法伪代码
-----------

```
//在链表L中搜索值为k的元素在哪个位置。
LIST-SEARCH(L, k)
	x = L.head
	while x != NIL and x.key != k
		x = x.next
	return x
	
//把值为x的元素插到链表L的最前端。
LIST-INSERT(L, x)
	x.next = L.head
	if L.head != NIL
		L.head.prev = x
	L.head = x
	x.prev = NIL
	
//删除链表L中第x个元素。
LIST-DELETE(L, x)
	if x.prev != NIL
		x.prev.next = x.next
	else L.head = x.next
	if x.next != NIL
		x.prev.next = x.prev
```