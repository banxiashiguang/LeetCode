# 给定两个单链表，找出公共节点。
给定两个单链表，若他们之间存在公共节点，返回指向公共节点的指针，不存在，则返回nullptr。  

## 算法
类似找出树节点的最近公共祖先类似，首先计算出两个单链表的长度lenA,lenB，两者中的较大者先走(|lenA-lenB|)步，最后两者共同走。  
