#include <iostream>
#include <string>
using namespace std;

class zigzagConversion
{
public:
	zigzagConversion() { }
	~zigzagConversion() { }
	string solution(string s,int nRows);
};

string zigzagConversion::solution(string s,int nRows)
{
	if(nRows <= 1)
		return s;
	string ret;
	int zigSize = 2*nRows - 2;
	for(int i = 0;i < nRows;i++)
	{
		for(int base = i;base < s.size();base += zigSize)
		{
			ret.append(1,s[base]);
			if(i > 0 && i < (nRows-1))
			{
				int ti = base + zigSize - 2 * i;
				if(ti < s.size())
				{
					ret.append(1,s[ti]);
				}
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	string s = "PAYPALISHIRING";
	zigzagConversion z;
	cout<<z.solution(s, 3)<<endl;
	return 0;
}