#include <iostream>
using std::cout;
using std::endl;
using std::max;

class jumpGameII
{
public:
	jumpGameII() { }
	~jumpGameII(){ }
	int solution(int A[],int n);
};

int jumpGameII::solution(int A[],int n)
{
	int curIndex = 0;
	for (int i = 0; i < curIndex && curIndex < n-1; ++i)
	{
		curIndex = max(i+A[i],curIndex);
	}
	return curIndex;
}