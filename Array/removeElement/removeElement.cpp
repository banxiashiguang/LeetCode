#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int> &nums,int val) {
		int index{0};
		for(int i = 0;i < nums.size(); ++i) {
			if(nums[i] != val) {
				nums[index] = nums[i];
				++index;
			}
		}
		return index;
	}
};

int main(int argc,const char *argv[]) 
{
	vector<int> nums{1,1,2,3,4,1};
	Solution s;
	cout << s.removeElement(nums,1) << endl;
	return 0;
}
