#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex+1);
		for(int i = 0; i <= rowIndex; ++i) {
			res[0] = 1;
			res[i] = 1;
			if(i > 1) {
				for(int j = i-1; j >= 1; --j)
					res[j] = res[j-1]+res[j];
			}
		}
		for(auto i:res)
			cout << i << "\t";
		cout << endl;
		return res;
	}
};


int main(int argc,const char *argv[])
{
	Solution s;
	s.getRow(2);
	return 0;
}
