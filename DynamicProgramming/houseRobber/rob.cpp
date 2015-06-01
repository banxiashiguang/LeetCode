#include <iostream>
#include <vector>
using namespace std;

calss Solution {
public:
	int rob(vector<int> &nums) {
		int len = nums.size();
		if(len == 0)
			return 0;
		vector<int> res(len+1,0);
		res[0] = 0;
		res[1] = nums[0];
		for(int i = 2; i <= len; ++i)
			res[i] = res[i-1] >= (res[i-2]+nums[i-1])? res[i-1]:(res[i-2]+nums[i-1]);
		return res[len];
	}
};
