#直接插入排序
算法思想：首先将第一个元素当作有序序列，后面的元素一次插入到前面的有序序列中。  
比较时应注意：将待插入的的元素和他之前的进行比较，若小于(大于)则进行交换，否则break;

#时间复杂度
最好情况下：待排序的序列有序，时间复杂度为O(n)  
最坏和平均时间复杂度：O(n^2)

#空间复杂度
使用常数空间O(1)

#算法稳定性
稳定排序