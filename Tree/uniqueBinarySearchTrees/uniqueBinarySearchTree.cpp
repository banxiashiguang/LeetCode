#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) { 
		vector<int> value(n+1);
		value[0] = 1;
		value[1] = 1;
		value[2] = 2;
		for(int i = 3; i <= n; ++i) {
			for(int j = 1; j <= i; ++j)
				value[i] += value[j-1]*value[i-j];
		}
		return value[n];
	}
};

int main(int argc,const char *argv[]) {
	Solution s;
	int num{0};
	while(cin >> num)
		cout << s.numTrees(num) << endl;
	return 0;
}
