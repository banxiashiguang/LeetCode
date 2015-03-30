#include <iostream>
using namespace std;

class trappingRainWater
{
public:
	trappingRainWater() { }
	~trappingRainWater() { }
	int solution(int A[],int n);
};

int trappingRainWater::solution(int A[],int n)
{
	if(n<=2)
		return 0;
	int index = 0;
	while(A[index]==0)
		index++;
	int sum = 0;
	int left = index;
	int right = n-1;
	int next = index+1;
	while(next<n)
	{
		int count = 0;
		while(A[next]<A[left] && next<n)
		{
			count += A[left]-A[next];
			next++;
		}
		if(next != n)
		{
			if(next != left+1)
				sum += count;
			left = next;
			next = left+1;
		}else{
			break;
		}
	}
	next = right-1;
	while(next>=left)
	{
		int count = 0;
		while(A[next]<A[right] && next>=left)
		{
			count += A[right]-A[next];
			next--;
		}
		if(next != left-1)
		{
			if(next+1 != right)
				sum += count;
			right = next;
			next = right-1;
		}else{
			break;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int n = sizeof(A)/sizeof(A[0]);
	trappingRainWater t;
	cout<<t.solution(A, n)<<endl;
	return 0;
}