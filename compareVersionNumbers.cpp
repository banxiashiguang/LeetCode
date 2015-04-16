/*
version命名规则：主版本号 . 子版本号 [. 修正版本号 [. 编译版本号 ]]
管理策略：
项目初版本时，版本号可以为 0.1 或 0.1.0，也可以为 1.0 或 1.0.0，如果你为人很低调，我想你会选择那个主版本号为 0 的方式；
当项目在进行了局部修改或 bug 修正时，主版本号和子版本号都不变，修正版本号加 1；
当项目在原有的基础上增加了部分功能时，主版本号不变，子版本号加 1，修正版本号复位为 0，因而可以被忽略掉；
当项目在进行了重大修改或局部修正累积较多，而导致项目整体发生全局变化时，主版本号加 1；
编译版本号一般是编译器在编译过程中自动生成的，我们只定义其格式，并不进行人为控制。
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class compareVersionNumbers
{
public:
	compareVersionNumbers() { }
	~compareVersionNumbers() { }
	void changeSubStr(string str,vector<int> &v);
	int solution(string version1,string version2);
};

/**
 * 解题思路：将string类型分割成小的子串，再将子串转换成整数。
 * 考虑特殊情况：1、若xxx.xxx.00.00.000 = xxx.xx
 */

void compareVersionNumbers::changeSubStr(string str,vector<int> &v)
{
	int left = 0;
	int i = 0;
	for (i = 0; i < str.size(); ++i)
	{
		if(str[i] != '.')
			continue;
		else{
			int tmp = 0;
			string sub = str.substr(left,i-left);
			istringstream ss(sub);
			ss >> tmp;
			v.push_back(tmp);
			left = i+1;
		}
	}
	int tmp = 0;
	string sub = str.substr(left,i-left);
	istringstream ss(sub);
	ss >> tmp;
	v.push_back(tmp);
}
void printVector(vector<int> &num)
{
	for(auto i:num)
		cout << i << "\t";
	cout << endl;
}
int compareVersionNumbers::solution(string version1,string version2)
{
	vector<int> v1;
	vector<int> v2;
	changeSubStr(version1, v1);
	changeSubStr(version2, v2);
	printVector(v1);
	printVector(v2);
	int len1 = v1.size();
	int len2 = v2.size();
	int index = 0;
	while(index < len1 && index < len2)
	{
		if(v1[index] > v2[index])
			return 1;
		if(v1[index] < v2[index])
			return -1;
		++index;
	}
	int tmp = index;
	while(index != len1)
	{
		if(v1[index] > 0)
			return 1;
		++index;
	}
	while(tmp != len2)
	{
		if(v2[tmp] > 0)
			return -1;
		++tmp;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	compareVersionNumbers c;
	cout << "resault：" << c.solution("1.0", "1") << endl;
	return 0;
}