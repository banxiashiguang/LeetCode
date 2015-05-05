#include <iostream>
#include <cmath>
using namespace std;

int coordinateToValue(int x,int y)
{
	//元素所在的层数
	int t = max(abs(x),abs(y));
	int res  = 0;
	int v = pow((2*t-1),2);
	if(y == -t)
		res = v+7*t+x;
	else if(y == t)
		res = v+3*t-x;
	else if(x == -t)
		res = v+5*t-y;
	else if(x == t)
		res = v+t+y;
	return res;
}

int main(int argc,const char *argv[])
{
	int n = 0;
	cout << "n=";
	cin >> n;
	const int N = n;
	for(int y = -N; y <= N;y++)
	{
		for(int x = -N; x <= N;x++)
			cout << coordinateToValue(x,y) << "\t";
		cout << endl;
	}
	return 0;
}
