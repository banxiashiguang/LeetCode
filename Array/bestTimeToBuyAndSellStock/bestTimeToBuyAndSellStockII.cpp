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
		int res = 0;
		for(int i = 1; i < len; ++i)
		{
			if(prices[i] > prices[i-1])
				res += (prices[i]-prices[i-1]);
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
