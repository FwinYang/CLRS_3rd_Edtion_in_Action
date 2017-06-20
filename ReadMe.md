算法导论（第三版）的编程实践
===================

这个repo是什么
----------------

这个repo将会用C++、C#、Java 和 python 等语言实现**算法导论第三版**中各个章节列举的数据结构与算法，**不包含对 算法设计/分析 、 数学定理推论/证明 和 课后题 的讨论**。

|       语言        |      语法标准     |        实现所用的IDE        |
|:-------------:|:---------------:|:------------------------:|
|       C++       |      C++14       |       VisulStudio 2015    |
|       C#          |      C#7            |       VisulStudio 2017    |
|       Java       |      Java8         |             仅源代码             |
|       python  |      python2.7  |            仅源代码             |

其中的有一些实现版本使用了各个语言的标准库中的基础内容（比如线性表），

如果书中更关注某些标准库里已有数据结构/算法的实现细节，那么这个repo里的代码将尽量避免使用标准库内容。

对于一部分算法，cpp版本提供了两种实现：

一种实现和算法导论书中的描述_几乎_完全一致（被我们称为**古典的C++实现方法**），另一种根据现代的C++语法特征尽可能的对算法进行简化（被我们称为**现代的C++实现方法**）。

对于其他语言版本，我们可能将在项目中提供两个类，一个类的代码实现更贴近算法导论中的伪代码描述，另一个类可能会包含一些个人的语法使用习惯，这两个类将以**Classic**和**Modern**命名。

我们会避免使用继承、模板等高级语言特性，专注于算法本身。

**在介绍每个数据结构/算法的ReadMe.md中，我们还交叉引用了[Leetcode](https://leetcode.com/)上的，和正在介绍的算法有关的 题目链接，有兴趣者可以很快学以致用。**

如果你是一个没有数学基础、对作为一门技术的算法感兴趣 并且 想了解一些常见抽象问题的最优解 的 程序设计人员，希望这个repo能够提供一些帮助。

如果你有一定的数学背景，希望这些具体实现能够提供一些编程思路方面的启发。

欢迎[PR](https://github.com/TiriSane/CLRS_3rd_Edtion_in_Action/pulls)和[讨论](https://github.com/TiriSane/CLRS_3rd_Edtion_in_Action/issues)。

更新进度
--------

- 2017.6.9 建立git repo，完成repo的说明文档。
- 2017.6.10 添加2.1 插入排序算法 、2.3.0 并归排序算法 和 2.3.1 冒泡排序算法。
- 2017.6.11 添加4.1 寻找最大非空子数组 算法。
- 2017.6.12 添加4.2 Strassen方阵乘法算法。
- 2017.6.13 添加6.1 最大二叉堆的数据结构存储形式的实现 和 6.2 维护最大堆的性质 算法。
- 2017.6.14 添加6.3 最大二叉堆的建立算法 和 6.4 堆排序 算法。
- 2017.6.15 添加6.5 最大优先队列的实现。
- 2017.6.16 添加7.1 快速排序算法 和 7.3 快速随机排序算法。
- 2017.6.17 添加8.2 计数排序算法 和 8.3 基数排序算法。
- 2017.6.18 添加8.4 桶排序算法。
- 2017.6.19 添加9.1 找到一个数组的最小值算法 、9.2 期望为线性时间的选择算法 和 9.3 最坏情况为线性时间的选择算法。
- 2017.6.20 添加10.1.0 栈的实现、10.1.1 队列的实现 和 10.2 链表的实现。

这个repo的体系结构
---------------------

1. 主目录下有以**Part  + 数字1~7**命名的七个文件夹，分别代表算法导论的（第三版）七个部分。
2. 二级目录下是一些以**Chapter + 数字**命名的文件夹，分别代表算法导论的（第三版）的各个章节（共35章）。因为有些章节没有具体的数据结构或算法描述，所以他们可能不在这个目录中。
3. 三级目录下以算法/数据结构所在的**小节名称** + **算法/数据结构本身的名称**命名。
4. 四级目录的文件夹包括**cpp**、**c#**和**java**等一些由不同语言名字命名的文件夹，还有一份含有算法简介和伪代码（附带书上注释）的**ReadMe.md**文档。
5. 五级目录下包括，一个或几个IDE项目文件和源代码文件夹，内含源代码。

对《算法导论（第三版）》的简介
----------------------------------

> 《算法导论（第三版）》是一本算法方面的经典书籍，它一直是MIT、CMU、Stanford、UCB、Cornel、UIUC 和 国内诸多名校 的教材。
> 《算法导论（第三版）》内容丰富，涵盖了典型算法、算法设计、算法分析、NP完全等内容，包括一些数据结构的介绍。
> 这本书的设计目标是全面地介绍当代计算机算法，提供对它们（尤其是运行效率上的）的分析，各个章节相对独立。
> 对于一些难理解的章节，书中建议我们在有一定数学背景和创造力之后再深入阅读。
> 阅读这本书需要有一些程序设计方面的经验，特别是需要理解递归过程、懂一些简单的数据结构，如数组和链表。对于推论分析部分，本书要求学生能较为熟练地利用数学归纳法进行证明，具备一些微积分、线性代数和离散数学的知识。
> 本书的补充材料、勘误和部分课后题的答案详见[这里](https://mitpress.mit.edu/books/introduction-algorithms)。

关于算法导论（第三版）伪代码的约定
---------------------------------------

**和C++类似的部分**

- 用缩进 代替 begin/end等标记 来表示语句块（block）结构。
- 使用while/for和if-else控制程序流程。
- 用//表示这行是注释
- =为赋值运算符，==判等运算符。多重赋值（形如i=j=k）的表达式是被允许的，=具有右结合性。
- 所有无特殊说明的变量都是局部变量，其生命周期和作用域和C++中自动变量的生命周期和作用域类似。
- 数组元素使用数组名[下标]的形式访问，比如A[i]代表数组A的第i个元素。
- 复合数据类型的组成方式和C++的对象类似，都可以使用点运算符访问对象的属性/方法（method）和数据成员。
- 形参的值传递给实参，然后它们就不关联了。数组在传递时会被隐式转换为指针。
- return语句结束当前函数。
- 逻辑运算符and（与）和or（或）是短路求值的。

**和C++不同的部分**

- 只使用缩进，不用大括号包裹一个块（block）。
- 使用repeat-until代表C++中的do..while循环。
- 退出循环后，循环计数器保持其值。
- 在for循环中使用to/downto关键字，to/downto之前是循环计数变量的定义，给了循环变量一个初始值，to/downto之后的值代表 当递增/递减到这个值时，循环终止
- 在循环语句中可以使用by关键字，使用方法是by 数字（比如for i=1 to 10 by 2）。意义和使用方法类似kotlin中的step，代表每次递增/递减的值为by后面那个数字的值。
- 如无特殊声明，数组下标从1开始而非从0开始。
- 记号..用来标记数组的一个子数组。比如A[1..10]就代表A的一个子数组，这个子数组包含A[1]、A[2]、A[3]、......A[10]。
- 点运算符所构成的表达式的值永远是一个左值。比如A.length = 3，把对象A的length属性的值改成3。
- 空指针用NIL表示（而不是nullptr）。
- 任何情况下return语句都可以有多个返回值。
- error关键字抛出异常，类似C++中的throw。无异常处理标记。
- 不必使用分号、而只是通过换行来结束一个语句。

贡献者
-------
- [TiriSane](https://github.com/TiriSane)
- [小楠](https://www.niconi.cn/)
- [yehuo](https://github.com/yehuo)