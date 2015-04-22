#直接插入
算法思想：将第一个带排序的元素作为有序序列，后面的元素以此插入到前面的有序序列中，
在查找对应的插入位置时，使用二分法进行查找。这样可以减少比较次数。  
注意细节：在二分法进行比较时，while时left <= right

#算法复杂度
若待排序的序列是有序的，则是最好情况时间复杂度为：O(n)  
最坏和平均时间复杂度：O(N^2)  在二分查找过程中时间复杂度为O(logi)，其中i是第i个元素，但是查找之后还需进行元素移动，故时间复杂度不是O(nlogn)

#空间复杂度
空间复杂度：O(1)

#算法稳定性
稳定排序