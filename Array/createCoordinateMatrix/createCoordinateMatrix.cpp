#include <iostream>
#include <vector>
using namespace std;

void createMatrix(vector<vector<int> > &matrix,int n)
{
	int m {1},i{0},j{0};
	for(i = 0; i < n/2; ++i)
	{
		//构造上面
		for(j = 0; j < n-i; ++j)
		{
			if(matrix[i][j] == 0)
				matrix[i][j] = m++;
		}
		
		//构造右面
		for(j = 0; j < n-i; ++j)
		{
			if(matrix[j][n-i-1] == 0)
				matrix[j][n-i-1] = m++;
		}

		//构造下面
		for(j = n-i-1; j > i;--j)
		{
			if(matrix[n-i-1][j] == 0)
				matrix[n-i-1][j] = m++;
		}

		//构造左面
		for(j = n-i-1; j > i; --j)
		{
			if(matrix[j][i] == 0)
				matrix[j][i] = m++;
		}
	}
	if(n%2 == 1)
		matrix[n/2][n/2] = m;
}

int main(int argc,const char *argv[])
{
	int n;
	cout << "n=";
	cin >> n;
	vector<vector<int> > matrix(n,vector<int>(n,0));
	createMatrix(matrix,n);
	for(auto i:matrix)
	{
		for(auto j:i)
			cout << j << "\t";
		cout << endl;
	}
	return 0;
}
