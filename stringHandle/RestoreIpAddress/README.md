##算法思想
由于IP的每个网段构造是都相同，所以利用递归的思想。  
首位可以是一个字符，后面分别构造1,2,3位的情况。
首位可以是两个字符，后面分别构造1,2,3位的情况。
首位可以是三个字符，后面分别构造1,2,3位的情况。

##递归函数的出口
1、后面剩余的字符长度不满足构造的需要或者大于构造的需要。  
2、最后一个字段构造完成，可以退出。

##注意情况
1、在构造的过程中，充分考虑0字符，只有一位时，开头可以为0;若大于1位，开头为0时，则是错误情况。  
2、for(int i = 1; i < 4 && i < right.size(); ++i) 加入i小于right.size()判断条件是为了1111这种情况时，如果后面没有字符可用，则会出错。