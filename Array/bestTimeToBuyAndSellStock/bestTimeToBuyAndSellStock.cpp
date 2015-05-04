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
		vector<int> minValue(len,0);
		minValue[0] = prices[0];
		vector<int> maxValue(len,0);
		maxValue[len-1] = prices[len-1];
		for(int i = 1; i < len; ++i)
			minValue[i] = min(minValue[i-1],prices[i]);
		for(int i = len-2; i >= 0; --i)
			maxValue[i] = max(maxValue[i+1],prices[i]);
		int res = 0;
		for(int i = 0; i < len; ++i)
		{
			res = max(maxValue[i]-minValue[i],res);
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{

	return 0;
}
