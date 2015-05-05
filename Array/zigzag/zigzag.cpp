#include <iostream>
#include <vector>
using namespace std;

void createZigZag(int n)
{
	vector<vector<int> > matrix(n,vector<int>(n));
	int value = 0;
	int s  = 0;
	int sum = n * n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			s =  i + j;
			if(s < n)
				matrix[i][j] = s * (s + 1)/2 + (s % 2 != 0? i:j);
			else{
				s = 2 * (n - 1) - (i + j);
				matrix[i][j] = (sum - s * (s + 1)/2) - (n - (((i + j)%2 == 0)? i:j));
			}
		}
	}
	for(auto i:matrix)
	{
		for(auto j:i)
			cout << j << "\t";
		cout << endl;
	}
}

int main(int argc,const char *argv[])
{
	int n;
	cout << "n=";
	cin >> n;
	createZigZag(n);	
	return 0;
}
