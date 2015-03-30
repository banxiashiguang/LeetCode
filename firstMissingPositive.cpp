#include <iostream>
#include <algorithm>
using namespace std;

class firstMissingPositive
{
public:
	firstMissingPositive(){ }
	~firstMissingPositive(){ }
	int solution(int A[],int n);
};

int firstMissingPositive::solution(int A[],int n)
{
	if(n==0)
		return 1;
	int index{0};
	sort(A,A+n);
	while(A[index]<=0)
		index++;
	if(index==n)
		return A[n-1]+1;
	else{
		int value {1};
		int last {-1};
		for(int i=index;i<n;i++)
		{
			cout<<"last="<<last<<"\t"<<"A["<<index<<"]="<<A[index]<<endl;
			if(A[i] != last)
			{
				if(A[i] != value)
					break;
				last = A[i];
				value++;
			}
		}
		return value;
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {0,2,2,1,1};
	int n = sizeof(A)/sizeof(A[0]);
	firstMissingPositive f;
	cout<<f.solution(A, n)<<endl;
	return 0;
}