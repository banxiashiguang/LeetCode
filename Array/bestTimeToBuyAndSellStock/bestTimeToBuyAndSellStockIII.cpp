#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int len = prices.size();
		if(len == 0 || len == 1)
			return 0;
		vector<int> frontMax(len,0);
		vector<int> backMax(len,0);
		int minPrice = prices[0];
		for(int i = 1; i < len; ++i)
		{
			minPrice = min(minPrice,prices[i]);
			frontMax[i] = max(frontMax[i-1],prices[i]-minPrice);
		}

		int maxPrice = prices[len-1];
		for(int i = len-2; i >= 0; --i)
		{
			maxPrice = max(prices[i],maxPrice);
			backMax[i] = max(backMax[i+1],maxPrice-prices[i]);
		}

		int res  = 0;
		for(int i = 0; i < len; ++i)
			res = max(res,frontMax[i]+backMax[i]);
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	vector<int> prices = {1,2};
	cout << s.maxProfit(prices) << endl;
	return 0;
}
