#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		map<int,int> value;	
		for(int i:nums)
			++value[i];
		for(auto iter:value) {
			if(iter.second < 3)
				return iter.first;
		}
	}
};

int main(int argc,const char *argv[]) {
	Solution s;
	vector<int> nums{1,2,3,3,2,1,1,3};
	cout << s.singleNumber(nums) << endl;
	return 0;
}
