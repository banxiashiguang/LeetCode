#include <iostream>
#include <vector>
using namespace std;

void primeNumber(int n)
{
	vector<bool> state(n+1,true);

	//奇数可能是素数，偶数一定不是素数。
	for(int i = 3; i <=n; ++i)
	{
		if(i%2 == 0)
			state[i] = false;
	}

	for(int i = 3; i <= n; i += 2)
	{
		for(int j = i+i; j <= n; j += i)
			if(state[j] == true)
				state[j] = false;
	}
	for(int i = 2; i <= n; ++i)
		if(state[i] == true)
			cout << i << " ";
	cout << endl;
}

int main(int argc,const char *argv[])
{
	primeNumber(100);
	return 0;
}
