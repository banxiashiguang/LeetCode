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
	if(A == NULL || n == 1)
		return 0;
	int ret = 0;//当前跳数
	int last = 0;//上一次能达到的最远距离
	int cur = A[0];//当前能到达的最远距离
	for (int i = 1; i < n; ++i)
	{
		if(i > cur)
			return -1;
		if(i > last)
		{
			last = cur;
			ret++;
		}
		if(i+A[i] > cur)
			cur = i+A[i];
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2};
	int n = sizeof(A)/sizeof(A[0]);
	jumpGameII j;
	cout<< j.solution(A, n) << endl;
	return 0;
}