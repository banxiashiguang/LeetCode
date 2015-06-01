#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums,int k) {
	size_t len = nums.size();
	if(k <= 0)
		return;
	k %= len;
	for(auto i:nums)
		cout << i << "\t";
	cout << endl;
	reverse(nums.begin(),nums.begin()+len-k);
	reverse(nums.begin()+len-k,nums.end());
	reverse(nums.begin(),nums.end());
	for(auto i:nums)
		cout << i << "\t";
	cout << endl;
}


int main(int argc,const char *argv[])
{
	vector<int> nums{1,2,3,4,5,6,7};
	rotate(nums,5);
	return 0;
}
