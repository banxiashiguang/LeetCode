#include <iostream>
#include<vector>
using namespace std;

bool use[10] = {0};
vector <long> v;
void dfs(int k, long a)
{
	if(k && a%k != 0)
		return;
	if(k == 9)
	{
		v.push_back(a);
		return;
	}
	for(int i = 1; i <= 9; ++i)
	{
		if(use[i] != 1)
		{
			use[i] = 1;
			dfs(k+1,a*10+i);
			use[i] = 0;
		}
	}
}
int main()
{
	dfs(0,0);
	cout << v.size() << endl;
	cout << v[0] << endl;
}
