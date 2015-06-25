#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a,string b) {
		int index1 = a.size()-1;
		int index2 = b.size()-1;
		int flags{0};
		string res;
		cout << index1 << "\t" << index2 << endl;
		while(index1 >= 0 && index2 >= 0) {
			int value = (int)(a[index1--]-'0')+(int)(b[index2--]-'0')+flags;
			res = (char)(value%2+'0')+res;
			flags = value/2;
		}
		cout << index1 << "\t" << index2 << endl;
		while(index1 >= 0) {
			int value = (int)(a[index1--]-'0')+flags;
			res = (char)(value%2+'0')+res;
			flags = value/2;
		}
		while(index2 >= 0) {
			int value = (int)(b[index2--]-'0')+flags;
			res = (char)(value%2+'0')+res;
			flags = value/2;
		}
		cout << res << endl;
		if(flags > 0)
			res = "1"+res;
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	cout << s.addBinary("11","111") << endl;
	return 0;
}
