#判定一个给定的值target是否在给定的矩阵matrix中
该矩阵为m ×n的大小。  
该矩阵有个特征是已经排序好的矩阵：每一行都是升序排列，下一行的第一个元素大于上一行的最后一个元素。

##利用二分搜索
1、首先另left = 0,right = (n * m)-1。mid = (left+right)>>1,row = mid /n,column = mid%n。  
2、如果，matrix[row,column] == target,返回true。  
3、如果，matrix[row,column] > target，当column == 0,right = (--row * n)+(n-1),否则，right = row * n + column - 1。  
4、如果，matrix[row,column] < target，当column = n-1,left = (++row) * n，否则，left = row * n + column +1。
