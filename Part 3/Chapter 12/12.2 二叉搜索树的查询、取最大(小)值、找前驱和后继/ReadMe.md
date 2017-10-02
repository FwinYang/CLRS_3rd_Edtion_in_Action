二叉搜索树的查询、取最大(小)值、找前驱和后继 算法
================================

算法概览
---------

**二叉搜索树的查询、取最大(小)值、找前驱和后继**算法是基于**二叉搜索树**的一些基本操作，

虽然看起来这五个不同的算法应该使用更多篇幅描述，不过它们都实现简单、容易理解，而且取最大(小)值算法互相对称、找前驱和后继算法也互相对称，只要理解了一个，就相应地也理解了另外一个。

因此放到一个小节里就可以说清楚了。不过这里还是要先明确一下前驱和后继的概念：

**前驱**：如果节点x的左子树非空，那么x的前驱恰好是x左子树里的最右节点。如果x的左子树为空且有一个前驱y，则这个前驱y是x的最底层祖先，且y的右孩子也是x的一个祖先。

**后继**：如果节点x的右子树非空，那么x的后继恰好是x右子树里的最左节点。如果x的右子树为空且有一个后继y，则这个后继y是x的最底层祖先，且y的左孩子也是x的一个祖先。

算法性能
---------

上述五个算法的时间复杂度均为：O(h)。

算法伪代码
------------

**查找**

```
TREE-SEARCH(x,k)
	if x == NIL or k == x.key
		return x
	if k<x.key
		return TREE-SEARCH(x.left, k)
	else return TREE-SEARCH(x.right, k)
```

**查找的非递归实现**

```
ITERATIVE-TREE-SEARCH(x,k)
	while x != NIL and k != x.key
		if k<x.key
			x = x.left
		else x = x.right
	return x
```

**取最小值**

```
TREE-MINIMUM(x)
	while x.left != NIL
		x = x.left
	return x
```

**取最大值**

```
TREE-MAXMUM(x)
	while x.right != NIL
		x = x.right
	return x
```

**求节点x的前驱**

```
TREE-PREDECCESSOR(x)
	if x.left != NIL
		return TREE_MAXIMUM(x.left)
	y = x.p
	while y != NIL and x == y.left
		x = y
		y = y.p
	return y
```

**求节点x的后继**

```
TREE-SUCCESSOR(x)
	if x.right != NIL
		return TREE_MINIMUM(x.right)
	y = x.p
	while y != NIL and x == y.right
		x = y
		y = y.p
	return y
```