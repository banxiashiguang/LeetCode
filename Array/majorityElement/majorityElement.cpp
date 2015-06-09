#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &nums) {
		int ret{nums[0]},count{1};
		for(int i = 1; i < nums.size(); ++i) {
			if(ret == nums[i])
				++count;
			else {
				--count;
				if(count == 0) {
					ret = nums[i];
					count = 1;
				}
			}
		}
		return ret;
	}
};

int main(int argc,const char *argv[])
{
	vector<int> nums{0,1,0,2,0};
	Solution s;
	cout << s.majorityElement(nums) << endl;
	return 0;
}
