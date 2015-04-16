#include <iostream>
#include <string>
using namespace std;

class validPalindrome
{
public:
	validPalindrome() { }
	~validPalindrome() { }
	bool isJump(char c)
	{
		if(c >= '0' && c <= '9')
			return false;
		if(c >= 'a' && c <= 'z')
			return false;
		if(c >= 'A' && c <= 'Z')
			return false;
		return true;
	}
	bool isEqual(char a,char b)
	{
		if(a == b)
			return true;
		else if((a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z' && ((a-32) == b)) || (b >= 'a' && b <= 'z' && a >= 'A' && a <= 'Z' && ((b-32) == a)))
			return true;
		else
			return false;
	}
	bool isPalindrome(string s)
	{
		if(s.size() == 0)
			return true;
		int left = 0;
		int right = s.size()-1;
		while(left < right)
		{
			while(left < right && isJump(s[left]))
				++left;
			while(left < right && isJump(s[right]))
				--right;
			cout << s[left] << "\t" << s[right] << endl;
			if(!isEqual(s[left], s[right]))
				return false;
			++left;
			--right;
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	validPalindrome v;
	cout << v.isPalindrome("1a2") << endl;
	return 0;
}