# 爬楼梯问题
在上楼梯的时候，我们可以选择一次一个台阶也可以一次两个台阶，那么求出到达第n个台阶时，我们有多少种方法。  
## 算法(动态规划)
考虑最后一步的走法：我们可以从第n-1个台阶也可以是第n-2个台阶，那么res[n] = res[n-1]+res[n-2]。  
构造大小为(n+1)的数组，第0、1、2台阶的初始值分别为0,1,2。  
