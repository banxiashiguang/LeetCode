#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int singleNumber(vector<int> &nums) {
			if(nums.empty())
				return 0;
			int resault{0},bitSum{0};
			for(int i = 0; i < 8*sizeof(int); ++i) {
				bitSum = 0;
				for(auto j:nums)
					bitSum += (j >> i) & 1;
				resault |= ((bitSum%3)<<i);
			}
			return resault;
		}
};

int main(int argc,const char *argv[]) {
	vector<int> nums{1,1,1,2};
	Solution s;
	cout << s.singleNumber(nums) << endl;
	return 0;
}
