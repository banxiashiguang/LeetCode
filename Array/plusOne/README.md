# 正整数存储在数组中,将该正整数加1

## 算法
方法一：按照加法步骤，设置一进位位，保存上一位加法的进位。最后需要判断进位位是否为1。  
方法二：在加法过程中，若当前位小于9，那么当前位加1,函数返回。否则当前位置1。循环结束后函数仍没有返回，那么需要在数组的头部插入数字1。  