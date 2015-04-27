#给定两个整数，返回从数组[1,2,3.....n]选出k个的所有可能。
例如：n=4,k=2那么应该返回[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]。  

##算法(利用递归，函数设为solve(res,curRes,n,k,start))
res：最终结果，curRes：保存每一个单一的结果，n：数组1....n，k：返回k个数，start：本轮递归开始的数字。  
for(int i = start; i <= n; ++i)  
{  
	curRes.push_back(i);  
	solve(res,curRes,n,k-1,i+1);  
	curRes.pop_back();  
}  
递归的出口：  k == 0。
