寻找最大非空子数组算法
===============

适用问题的描述
----------------

**寻找最大非空子数组**算法 要解决的问题是一种特定的问题，这种算法会找出一个数组（通常包括负数）的子数组，这个子数组的值之和是所有情况中最大的那种：

输入：n个数的一个序列<a1，a2，...，an>
输出：输入序列的一个子序列<ax，ax+1，...，ay>，满足x>=0，y<=n，x<y。并且这个子序列是所有子序列中值的和最大的一种。

算法性能
---------

最坏情况下时间复杂度：O(nlgn)。

平均/期望的时间复杂度：O(nlgn)。

书中提出这个算法的教学目的
-----------------------------

书中第四章是关于分治算法的实现，通过这个算法，书中讨论了求解递归式的方法 和 分解-解决-合并的步骤。

寻找最大非空子数组并不是一个典型的分治算法，一个典型的分治算法把它要处理的问题化简为数个子问题，每一个子问题都是相同的，只不过规模更小了。

书上面说的这种 寻找最大非空子数组的非暴力 算法把问题拆成三种情况分析，衍生出三种子问题，并把这三种子问题的解整合起来，合成子问题的解，再进行递归，这个算法有着给人启发的设计。

**算法思路描述**

本算法对于一个待分析的数组，把这个数组分成尽量等大小的两个部分，这时，最大子数组的位置有三种情况：

1. 这个最大子数组可能是完全在左半边里。
2. 这个最大子数组可能是完全在右半边中。
3. 这个最大子数组可能跨过子数组的中线，它的一部分在左半边，一部分在右半边。

因此，这个算法对每一个待处理的数组进行以下处理：

1. 寻找左子数组的最大子数组。
2. 寻找右子数组的最大子数组。
3. 寻找一部分在左边数组，另一部分又在右边数组里的，最大子数组。

当这个算法待处理的数组A只有一个元素时，这个元素本身构成的数组就是这个待处理数组A的最大子数组。

当上句话中这个最大子数组A是另外一个待处理数组B的左子数组时，这个待处理数组B的最大子数组是 最大左子数组A、最大有子数组B、最大横跨左右子数组C 中 更大的一个。
因此可以有一个解，并且这个算法流程返回上一级递归调用。

Leetcode中有[一道题](https://leetcode.com/problems/maximum-subarray/#/description)就可以使用这个算法解决。

算法伪代码
-----------

**代码片段1**

```
//这段代码展示的是 寻找最大非空子数组算法 中的“寻找待处理数组中，一部分在左边数组，另一部分又在右边数组里的，最大子数组”这一过程，而非**寻找最大非空子数组算法**的全部。
//待找出最大子数组的数组为A，low、mid和high 分别代表这个最大子数组在最初处理的那个数组中的首元素下标、中间元素下标 和 尾部元素下标。
// sum是一个临时变量，用于几轮求和的临时值。
//left-sum和right-sum分别目前找到 "最大横跨左右子数组" 中最大的元素值之和。max-left和max-right分别代表我们找到的"一部分在左边数组，另一部分又在右边数组里的，最大子数组"相对于初始数组的最左边元素下标和最右边元素下标。
FIND-MAX-CROSSING-SUBARRAY(A,low,mid,high)
	left-sum = -∞
	sum = 0
	for i = mid downto low
		sum = sum + A[i]
		if sum > left-sum
			left-sum = sum
			max-left = i
		
	right-sum = -∞
	sum = 0
	for i = mid+1 to high
		sum = sum + A[j]
		if sum > right-sum
			right-sum = sum
			max-right = j

	return (max-left,max-right,(left-sum)+(right-sum))
```
	
**代码片段2**

```
//这段代码展示的是整个 寻找最大非空子数组算法 函数，这个函数通过调用上面的FIND-MAX-CROSSING-SUBARRAY函数进行递归的寻找最大子数组。
//left-low,left-high、right-low,right-high代表已找到的左右子数组中的最大数组。
//left-sum、right-sum和cross-sum是指找到的左中右三个最大子数组分别的元素之和的最大值。
FIND-MAXIMUM-SUBARRAY(A,low,high)
	if high == low
		return (low,high,A[low])      //最基础的数组：只有一个元素
	else mid = (low+high)/2
		(left-low, left-high, left-sum) = 
			FIND-MAXIMUM-SUBARRAY(A,low,mid)
		(right-low, right-high, right-sum) = 
			FIND-MAXIMUM-SUBARRAY(A,mie+1,high)
		(cross-low, cross-high, cross-sum) = 
			FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
			
		if left-sum>=right-sum and left-sum >=cross-sum
			return (left-low, left-high, left-sum)
		else if right-sum>=left-sum and right-sum >=cross-sum
			return (right-low, right-high, right-sum)
		else
			return (cross-low, cross-high, cross-sum)
```