##股票最大收益
给定一个数组prices，数组中第i个元素prices[i]代表第i天的股票价格为prices[i]。求在给定条件下股票的最大收益。  

##算法1(允许至多一次的买进卖出，求最大的收益)
要求一次买进卖出的最大值，假设从第1天到第n天每天买进卖出的最大收益，然后从中取最大值。  
假设求i天的最大收益，需要求出从1...i中的最小值，从i+1...n中的最大值。两者相减即可。  
1、开辟两个数组minValue,maxValue，minValue[i],maxValue[i]分别保存1...i的最小值和i+1...n的最大值。  
2、取出maxValue,minValue对应相减的最大值。  

##时间复杂度
时间复杂度：O(n)。  

##算法2(可以任意多次的买进卖出，但是买进之前手里不能有股票)
任意多次的买进卖出，求获取的最大利益，要获取最大利益只需要获得每个递增区间，然后将各个增区间相加即可。  

##时间复杂度
时间复杂度：O(n)。

##算法3(任意两次的买进卖出，买进之前手里不能有股票)
可以将数组prices分成前后两个部分，frontMax[1...i],backMax[i+1...n]两个部分的最大值相加即可。  
minPrice = prices[0]，i从1...n获得当前买入卖出的最大值，minPrice = min(minPrice,prices[i]),frontMax[i] = max(frontMax[i-1],prices[i]-minPrices)。  
maxPrice = prices[prices.size()-1],i从n-2....0获取当前买入卖出的最大值，maxPrice = max(maxPrice,prices[i]),backMax[i] = max(backMax[i-1],maxPrice-prices[i])。  

##时间复杂度
时间复杂度：O(n)。
