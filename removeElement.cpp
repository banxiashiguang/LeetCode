#include <iostream>
using namespace std;

class removeElement
{
public:
	removeElement() { }
	~removeElement() { }
	int solution(int A[],int n,int elem);
};

int removeElement::solution(int A[],int n,int elem)
{
	int index = 0;
	for(int i=0;i<n;i++)
	{
		if(A[i] != elem)
		{
			A[index] = A[i];
			index++;
		}
	}
	for(int i=0;i<index;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
	return index;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,3,2,1,4,5,1};
	int n = sizeof(a)/sizeof(a[0]);
	removeElement r;
	cout<<r.solution(a, n, 1)<<endl;
	return 0;
}