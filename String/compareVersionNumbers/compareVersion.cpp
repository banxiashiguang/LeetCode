#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
	int substrToInt(const string str,int &start) {
		int index = str.find('.',start);
		int res{0};
		if(index != string::npos) {
			res = stoi(str.substr(start,index-start));
			start = index+1;
		}else{
			res = stoi(str.substr(start,str.size()-start));
			start = str.size();
		}
		return res;
	}
	int compareVersion(string version1,string version2) {
		int start1{0},start2{0};
		int len1 = version1.size();
		int len2 = version2.size();
		while(start1 < len1 && start2 < len2) {
			//cout << "start1=" << start1 << "\t" << "start2=" << start2 << endl;
			int value1 = substrToInt(version1,start1);
			int value2 = substrToInt(version2,start2);
			//cout << "value1=" << value1 << "\t" << "value2=" << value2 << endl;
			//cout << "start1=" << start1 << "\t" << "start2=" << start2 << endl;
			if(value1 > value2)
				return 1;
			if(value1 < value2)
				return -1;
		}
		while(start1 != len1) {
			int value1 = substrToInt(version1,start1);
			if(value1 > 0)
				return 1;
		}
		while(start2 != len2) {
			int value = substrToInt(version2,start2);
			if(value > 0)
				return -1;
		}
		return 0;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	string v1,v2;
	while(getline(cin,line)) {
		istringstream ss(line);
		ss >> v1 >> v2;
		cout << v1 << "\t" << v2 << ":";
		cout << s.compareVersion(v1,v2) << endl;
		cout << endl;
	}
	return 0;
}
