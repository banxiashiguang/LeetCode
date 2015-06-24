#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int> &nums1,int m,vector<int> &nums2,int n) {
		if(n <= 0)
			return;
		int index1{0};
		while(index1 < m) {
			if(nums1[index1] > nums2[0]) {
				swap(nums1[index1],nums2[0]);
				for(int i = 1; i < n; ++i) {
					if(nums2[i] < nums2[i-1])
						swap(nums2[i],nums2[i-1]);
					else
						break;
				}
			}
			++index1;
		}
		int index2{0};
		for(int i = index1; i < n+index1; ++i)
			nums1[i] = nums2[index2++];
		for(auto i:nums1)
			cout << i << "\t";
		cout << endl;
	}
};

int main(int argc,const char *argv[]) {
	vector<int> nums1{1,2,4,5,6,0};
	vector<int> nums2{3};
	Solution s;
	s.merge(nums1,5,nums2,1);
	return 0;
}
