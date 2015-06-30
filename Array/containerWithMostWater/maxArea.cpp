#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int calArea(int value1,int index1,int value2,int index2) {
		cout << value1 << "\t" << index1 << "\t" << value2 << "\t" << index2 << endl;
		return (min(value1,value2)*(index2-index1));
	}
	int maxArea(vector<int> &height) {
		int left = 0;
		int right = height.size()-1;
		int max = 0;
		while(left < right) {
			while(height[left] == 0)
				++left;
			while(height[right] == 0)
				--right;
			int area = calArea(height[left],left,height[right],right);
			if(max < area)
				max = area;
			if(height[left] <= height[right])
				left++;
			else
				right--;
		}
		return max;
	}
};

int main(int argc,const char *argv[])
{
	vector<int> height{1,1};
	Solution s;
	cout << s.maxArea(height) << endl;
	return 0;
}
