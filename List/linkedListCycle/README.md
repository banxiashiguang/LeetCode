##判断一个单链表是否有环(Linked List Cycle)
给定一个单链表head，判断在head中是否存在环路。  
##算法思想
设置两个快慢指针，slow=head，fast=head-> next。  
首先判断slow是否等于fast，防止(head-> next = head的情况),等于退出，否则，slow走一步，fast先走一部，判断是否为NULL，不是再走一步，为NULL退出。总结来说就是slow走一步，fast走两步，若存在环，fast最终会追上slow。  

##若单链表存在环，链表环的入口节点(Linked List Cycle II)
给定一个单链表，找出链表环的入口节点。

##算法(自己)
经过判断是否有环之后，那么slow，fast执行同一个节点。新建指针p=head，步骤如下：  
1、判断p所指的节点是否为入口节点，如果fast-> next == p，那么p就是入口节点,否则  
2、fast=fast-> next,遍历环直到slow，在遍历过程中，判断fast-> next是否指向p，是的话，p就是入口节点。  
3、否则，p=p-> next,重复1、2步骤。  

##时间复杂度
每一次遍历，都需要遍历一遍环，所以时间复杂度为O(n^2)。  

##算法2(利用单链表的各个部分的长度来计算)
a:从head到链表环的入口节点的距离。  
b:从入口节点到slow和fast相遇的时的距离。  
L:环的长度。  
s:slow从开始到与fast相遇时走过的距离，那么fast走过的距离是2s。  
n:fast与slow相遇时已经走过n圈。  
具体的计算过程如下：  
s=a+b,2s=nL+a+b 从而推出:a+b=nL ---> a=nL-b ---> a=(n-1)L+(L-b)。令slow指向head，slow，fast都向前走一步，最终经过a步之后，slow和fast都指向链表环的入口节点。  

##时间复杂度
时间复杂度为O(n)。  
