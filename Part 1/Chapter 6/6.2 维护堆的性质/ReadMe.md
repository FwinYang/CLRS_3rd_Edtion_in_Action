MAX-HEAPIFY算法（用于维护最大二叉堆的性质）
===============================

适用问题的描述
----------------

**MAX-HEAPIFY**算法 要解决的问题是一种特定的问题，这种算法用于维护最大二叉堆的性质，即上层的数值比下层的数值大，

这个算法的输入为一个数组A和下标i，在调用MAX-HEAPIFY的时候，我们假定根节点为LEFT(i)和RIGHT(i)的二叉树都是最大堆，

但是这是A[i]本身可能小于其孩子，这样就违背了最大堆的性质。

MAX-HEAPIFY通过让A[i]的值在最大堆中“逐级下降”，从而使得以下标i为根结点的子树重新遵循最大堆的性质。

算法性能
---------

最坏情况下时间复杂度：O(h)。

平均/期望的时间复杂度：O(h)。

h为最大二叉堆的高度。

书中提出这个算法的教学目的
-----------------------------

这个算法先取A[i]的左子节点l和右子节点r（如果它们存在的话）。

并把A[i]先后与l和r比较，

如果A[i]不是三者中最大的，就与三者中最大的交换位置，再以换过位置的A[i]为新根节点，对这个节点执行MAX-HEAPIFY算法

算法伪代码
-----------

```
MAX-HEAPIFY(A,i)
	l = LEFT(i)
	r = RIGHT(i)
	if l <=A.heap-size and A[l]>A[i]
		largest = l
	else largest = i
	if r<=A.heap-size and A[r] > A[largest]
		largest = r
	if largest != i
		把A[i]和A[largest]交换
		MAX-HEAPIFY(A,largest)
		
```