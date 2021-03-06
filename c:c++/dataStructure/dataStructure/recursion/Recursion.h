//
//  Recursion.h
//  dataStructure
//
//  Created by 杨 on 16/5/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
 * 观察归纳法我们发现：递归的数学模型就是归纳法：
 * 归纳法适用于把一个问题转换为他的子问题，而他的子问题又转化为子问题；
 * 而且我们发现这些问题都有一个模型：存在相同的逻辑归纳处理项。
 * 当然也有一个例外：递归结束处的处理方法不适用于这个模型。
 * 于是又引出一个归纳终结点以及直接求解表达式。
 * 大致总结下归纳法的组成部分：
 * 1.步进表达式：问题蜕变为子问题的表达式。
 * 2.结束条件：什么时候可以不再适用步进表达式。
 * 3.直接求值表达式：在结束条件下能够直接计算返回值的表达式。
 * 对于递归，最好的理解方式便是从函数的功能意义的层面来理解。
 * 了解一个问题如何被分解为它的子问题，这样对于递归函数代码也就理解了。
 * 这里有一个误区（我也曾深陷其中），就是通过分析堆栈，分析一个一个函数的调用过程、输出结果来分析递归的算法。
 * 这是十分要不得的，这样只会把自己弄晕，其实递归本质上也是函数的调用，调用的函数是自己或者不是自己其实没什么区别。在函数调用时总会把一些临时信息保存到堆栈，堆栈只是为了函数能正确的返回，仅此而已。
 * 我们只要知道递归会导致大量的函数调用，大量的堆栈操作就可以了。
 * 小结:
 * 递归的基本思想是把规模大的问题转化为规模小的相似的子问题来解决。
 * 在函数实现时，因为解决大问题的方法和解决小问题的方法往往是同一个方法，所以就产生了函数调用它自身的情况。
 * 另外这个解决问题的函数必须有明显的结束条件，这样就不会产生无限递归的情况了。
 * 缺点：
 * 我们知道，递归调用实际上是函数自己在调用自己，而函数的调用开销是很大的.
 * 大家都知道递归的实现是通过调用函数本身，函数调用的时候，每次调用时要做地址保存，参数传递等.
 * 这是通过一个递归工作栈实现的。具体是每次调用函数本身要保存的内容包括：局部变量、形参、调用函数地址、返回值。那么，如果递归调用N次，就要分配N*局部变量、N*形参、N*调用函数地址、N*返回值。这势必是影响效率的。
 
 * 递归是利用系统的堆栈保存函数当中的局部变量来解决问题的。递归说白了就是在栈处理栈上一堆的指针指向内存中的对象，这些对象一直不被释放，直到递归执行到最后一次跳出条件的时候，才一个个出栈。所以开销很大。
 递归与循环比较：
 1. 递归算法：
 
 优点：代码简洁、清晰，并且容易验证正确性。（如果你真的理解了算法的话，否则你更晕）
 缺点：它的运行需要较多次数的函数调用，如果调用层数比较深，需要增加额外的堆栈处理（还有可能出现堆栈溢出的情况），比如参数传递需要压栈等操作，会对执行效率有一定影响。但是，对于某些问题，如果不使用递归，那将是极端难看的代码。
 2. 循环算法：
 
 优点：速度快，结构简单。
 缺点：并不能解决所有的问题。有的问题适合使用递归而不是循环。如果使用循环并不困难的话，最好使用循环。
 3. 递归算法和循环算法总结：
 
 递归通常很直白地描述了一个求解过程，因此也是最容易被想到和实现的算法。循环其实和递归具有相同的特性（即：做重复任务），但有时，使用循环的算法并不会那么清晰地描述解决问题步骤。单从算法设计上看，递归和循环并无优劣之别。然而，在实际开发中，因为函数调用的开销，递归常常会带来性能问题，特别是在求解规模不确定的情况下。而循环因为没有函数调用开销，所以效率会比递归高。除少数编程语言对递归进行了优化外，大部分语言在实现递归算法时还是十分笨拙，由此带来了如何将递归算法转换为循环算法的问题。算法转换应当建立在对求解过程充分理解的基础上，有时甚至需要另辟蹊径。
 
 一般递归调用可以处理的算法，也通过循环去解决需要额外的低效处理。
 现在的编译器在优化后，对于多次调用的函数处理会有非常好的效率优化，效率未必低于循环。
 递归和循环两者完全可以互换。如果用到递归的地方可以很方便使用循环替换，而不影响程序的阅读，
 那么替换成递归往往是好的。（例如：求阶乘的递归实现与循环实现。）
 要转换成为非递归，两步工作：
 
 第一步，可以自己建立一个堆栈保存这些局部变量，替换系统栈；
 第二步把对递归的调用转变为循环处理就可以了。
 那么递归使用的栈是什么样的一个栈呢？
 
 首先，看一下系统栈和用户栈的用途。
 
 系统栈（也叫核心栈、内核栈）是内存中属于操作系统空间的一块区域，其主要用途为：
 保存中断现场，对于嵌套中断，被中断程序的现场信息依次压入系统栈，中断返回时逆序弹出；
 保存操作系统子程序间相互调用的参数、返回值、返回点以及子程序(函数)的局部变量。
 用户栈是用户进程空间中的一块区域，用于保存用户进程的子程序间相互调用的参数、返回值、返回点以及
 子程序(函数)的局部变量。
 我们编写的递归程序属于用户程序，因此使用的是用户栈。
 */
#ifndef Recursion_h
#define Recursion_h
class Recursion {
public:
    // n的阶乘
    int factorial(int n)
    {
        if (n == 1) { // 结束条件
            return 1; // 直接求值表达式
        }
        return n * factorial(n-1); // 归纳出的步进表达式： n的阶乘＝n* (n-1)的阶乘
    }
    // 斐波那契数列
    int fibonacci(int n)
    {
        if (n == 0 || n == 1) { // 结束条件
            return 1; // 直接求值表达式
        }else { // 归纳出的步进表达式： 当前数总等于前两个数之和
            return fibonacci( n - 1) + fibonacci(n - 2);
        }
    }
    // 判断回文字符串
    bool isPalindereme(char* str,int n)
    {
        if (n == 0 || n == 1) { // 结束条件
            return true; // 直接求值表达式
        }
        if (str[0] != str[n-1]) { // 结束条件
            return false; // 直接求值表达式
        }else {
            return isPalindereme(str+1, n-2); // 归纳出的步进表达式：除去首尾字符再判断
        }
    }
    // 二分法查找
    bool binarySearch(int* arr,int n,int key)
    {
        // 结束条件：1.找到了 2.二分后的数组只有一个元素
        // 直接求值表达式 true false
        // 归纳出的步进表达式：
        // 中间值大于key 前半部分继续二分查找 中间值小于key 后半部分继续二分查找
        if (n == 1) {
            return (arr[0] == key);
        }else {
            int mid =  n/2;
            if (arr[mid-1] == key) {
                return true;
            }else {
                if (arr[mid] > key) {
                    return binarySearch(arr, mid, key);
                }else {
                    return binarySearch(arr+mid, n-mid, key);
                }
            }
        }
    }
};
#endif /* Recursion_h */
