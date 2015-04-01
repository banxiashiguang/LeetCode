//二维数组顺时针旋转90度
#include <iostream>
#include <vector>
using namespace std;

class rotateImage
{
public:
	rotateImage() { }
	~rotateImage() { }
	void solution(vector<vector<int> > &matrix);
};

//占用额外的空间O(n^2)，题目中要求只占O(1)，不符合题意。
/*void rotateImage::solution(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	vector<vector<int> > tmp(n);
	for (int i = 0; i < n; ++i)
	{
		tmp[i].resize(n);
	}
	for (int i = 0; i < n; ++i)
	{
		int row = 0;
		int col = n-i-1;
		for (int j = 0; j < n; ++j)
		{
			tmp[row++][col] = matrix[i][j];
		}
	}
	matrix = tmp;
}*/

void rotateImage::solution(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	for (int i = 0; i < n/2; ++i)
	{
		for (int j = i; j < n-i-1; ++j)
		{
			int tmp = matrix[j][n-i-1];
			matrix[j][n-i-1] = matrix[i][j];
			matrix[i][j] = matrix[n-j-i][i];
			matrix[n-j-i][i] = matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1] = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}