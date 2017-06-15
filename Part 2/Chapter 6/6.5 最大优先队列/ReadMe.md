最大优先队列（数据结构）
================

数据结构描述
----------------

堆这一数据结构有很多应用，其中一种就是优先队列。

优先队列也和（二叉）堆一样，分成两种，最大优先队列（基于最大堆）和最小优先队列（基于最小堆）。

最大优先队列通常用于在共享计算机系统里的作业调度。

通常数据结构支持的基础操作
-----------------------------

**对于最大优先队列**

1. INSERT(x) 

```
MAX-HEAP-INSERT(x)
	A.heap-size = A.heap-size+1
	A[A.heap-size] = -∞
	HEAP-INCREASE-KEY(A, A.heap-size, key)
```

2. MAXIMUN 方法，用于返回最大优先队列中最大的元素（对于最小优先队列，返回最小的那个）

```
HEAP-MAXIMUM(A)
	return A[1]
```

3. EXTRACT-MAX 方法，用于返回最大优先队列中最大的元素并把这个元素从最大优先队列中删除。

```
HEAP-EXTRACT-MAX(A)
	if A.heap-size<1
		error "heap underflow"
	max = A[1]
	A[1]=A[A.heap-size]
	A.heap-size = A.heap-size - 1
	MAX-HEAPIFY(A, 1)
	return max
```

4. INCREASE-KEY(x, k) 方法，用于把下标为x的元素的值增加到k。

```
HEAP-INCREASE-KEY(A, i, key)
	if key < A[i]
		error "new key is smaller than current key"
	A[i] = key
	while i >1 and A[PARENT(i)] < A[i]
		交换A[i]和A[PARENT(i)]
		i  = PARENT(i)
```