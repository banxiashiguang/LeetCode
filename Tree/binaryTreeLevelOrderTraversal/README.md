# 将二叉树的每一层所含有的元素值保存在二维数组中

## 算法
二叉树的广度遍历

## 小技巧
如何区分每一层的结尾：可以在每一层元素结尾时，再次插入一个nullptr。  

## 亦错点
遍历到最后一层的时候，需要在循环外将最后一层的元素加入到二维数组中。  