#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string res;
		vector<int> value{1000,900,500,400,100,90,50,40,10,9,5,4,1};
		vector<string> ch{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		while(num > 0) {
			for(int i = 0; i < value.size(); ++i) {
				if(num >= value[i]) {
					res += ch[i];
					num -= value[i];
					break;
				}
			}
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	cout << s.intToRoman(3999) << endl;
	return 0;
}
