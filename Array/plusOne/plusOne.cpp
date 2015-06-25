#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		for(int i = digits.size()-1; i >= 0; --i) {
			if(digits[i] < 9) {
				++digits[i];
				return digits;
			}else{
				digits[i] = 0;
			}
		}
		digits.insert(digits.begin(),1);
		return digits;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	vector<int> digits{9,9,9};
	vector<int> res = s.plusOne(digits);
	for(auto i:res)
		cout << i << "\t";
	cout << endl;
	return 0;
}
