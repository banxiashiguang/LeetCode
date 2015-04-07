#include <iostream>
#include <vector>
using namespace std;

class spiralMatrixII
{
public:
	spiralMatrixII() { }
	~spiralMatrixII() { }
	vector<vector<int> > solution(int n);
};

/**
 * 设置一个标记(m,n),标记每一层左上角的元素。
 */
vector<vector<int> > spiralMatrixII::solution(int n)
{
	vector<vector<int> > res;
	int **A = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}
	int a = 0,b = 0;
	int row = n-1,col = n-1;
	int index = 1;
	for (int i = 0; i < (n-1)/2+1; ++i)
	{
		for (int j = a; j <= col; ++j)
			A[a][j] = index++;
		for(int j = a+1;j <= row-1;++j)
			A[j][col] = index++;
		if(a != row)
		{
			for(int j = col;j >= b;--j)
				A[row][j] = index++;
		}
		for(int j = row-1;j >= a+1;--j)
			A[j][b] = index++;
		++a;
		++b;
		--row;
		--col;
	}
	for (int i = 0; i < n; ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < n; ++j)
			tmp.push_back(A[i][j]);
		res.push_back(tmp);
	}
	for (int i = 0; i < n; ++i)
	{
		delete [] A[i];
	}
	delete [] A;
	return res;
}

int main(int argc, char const *argv[])
{
	spiralMatrixII s;
	s.solution(3);
	return 0;
}