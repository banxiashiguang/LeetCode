##删除已经排序好的链表中重复的元素
给定一个链表head，删除链表中重复的元素。分为两种情况：1、重复的元素只保留一个。2、重复的元素不进行保留，都删除干净。  

##算法1(保留一个)
设置两个指针p指向当前遍历的的元素，prev指向上一个元素，last保留上一个元素的值，那么分为以下两种情况：  
1、p指向的元素的值和last相等，那么用临时变量tmp指向p，prev-> next = p-> next,prev = p-> next;p = prev-> next。删除tmp只想的元素。  
2、P指向的元素的值和last不想等，那么，prev = p; p = p-> next。  

##算法2(不保留)
指针newHead指向新建的节点对象,指针tail指向尾部，初始化为tail = newHead。在遍历head的过程中p指向当前元素，prev只想重复元素的第一个,last保存上一个元素的值，count保存重复元素的个数。那么：  
1、p指向的元素的值等于last，p=p-> next,count++。  
2、p指向的元素的值不等于last，首先判断count是否大于0,如果不大于0,则last = p-> val,tail-> next = prev;tail = tail-> next, prev = p,p = p-> next。  
如果count大于0,那么删除prev和p之间的元素，last = p-> val,count = 0,tail-> next = prev;tail = tail-> next,p = p-> next。  
##算法2注意的细节
如果head的最后几个元素是重复的元素的话，那么tail-> next = NULL。
