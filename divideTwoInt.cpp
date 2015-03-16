#include <iostream>
#include <limits>
using namespace std;

class divideTwoInt
{
public:
	divideTwoInt() { }
	~divideTwoInt() { }
	int solution(int dividend,int divisor);	
};

int divideTwoInt::solution(int dividend,int divisor)
{
	int i =0,flags=0;
	long long n = 0;
	long long index[100],value[100];
	long long dend = (long long)dividend;
	long long dsor = (long long)divisor;
	if(dend < 0)
	{
		dend = -dend;
		flags++;
	}
	if(dsor < 0)
	{
		dsor = -dsor;
		flags++;
	}
	cout<<flags<<endl;
	index[1] = 1;
	value[1] = dsor;
	for(i=2;value[i-1]<=dend;i++)
	{
		index[i] = index[i-1]+index[i-1];
		value[i] = value[i-1]+value[i-1];
	}
	i--;
	while(dend >= dsor && i>0)
	{
		if(dend >= value[i])
		{
			dend -= value[i];
			n += index[i];
		}
		i--;
	}
	if(flags == 1)
	{
		if(-n < numeric_limits<int>::min())
			return numeric_limits<int>::min();
		else
			return -n;
	}else{
		if(n >numeric_limits<int>::max())
			return numeric_limits<int>::max();
		else
			return n;
	}
}

int main(int argc, char const *argv[])
{
	divideTwoInt d;
	cout<<d.solution(-2147483648, -1)<<endl;
	return 0;
}