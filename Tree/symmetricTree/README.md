# 判断一棵二叉树是否对称
给定一棵二叉树root,判断该二叉树是否对称。  

## 算法(递归)
递归函数judgement,参数为两个指向树节点的指针pLeft,pRight，分别初始化为root节点的左右子树.  
1、若pLeft和pRight都不为空，那么若两个指针指向的元素的值不想等，返回false，否则递归judgement(pLeft::left,pRight::right) && judgement(pLeft::right,pRight::left)。  
2、若pLeft和pRight有且仅有一个为空，那么返回false。  
3、若pLeft和pRight都为空，那么返回true。  

## 细节
根节点为空或者只有根节点一个元素值时，另外判断。  
