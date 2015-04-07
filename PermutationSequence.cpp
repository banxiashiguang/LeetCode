#include <iostream>
#include <string>
using namespace std;

class PermutationSequence
{
public:
	PermutationSequence() { }
	~PermutationSequence(){ }
	string solution(int n,int k);
};

string PermutationSequence::solution(int n,int k)
{
	string res = "";
	int pCount = 1;
	int *A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = i+1;
		pCount *= (i+1);
	}
	k--;//k减1的原因：k正好等于(例如(n-1)!)界限值
	for (int i = 0; i < n; ++i)
	{
		pCount = pCount/(n-i);
		int select = k/pCount;
		k = k%pCount;
		res += (A[select]+'0');
		for (int j = select; j < n-i-1; ++j)//将空格之后的元素进行前移.
		{
			A[j] = A[j+1];
		}
	}
	delete [] A;
	return res;
}

int main(int argc, char const *argv[])
{
	PermutationSequence p;
	cout << p.solution(8, 8590) << endl;
	return 0;
}