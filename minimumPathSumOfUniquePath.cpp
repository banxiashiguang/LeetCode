#include <iostream>
#include <vector>
using namespace std;

class minimumPathSumOfUniquePath
{
public:
	minimumPathSumOfUniquePath() { }
	~minimumPathSumOfUniquePath() { }
	int solution(vector<vector<int> > &grid);
};

/**
 * 题意：求路径经过的线上元素的最小值(grid为填充不同元素的二维vector对象)
 * 解题思路：利用DP思想,求出局部的最小值,下一步从最小值中，选出最小的.
 * tmp中保存到达该位置，经过的路径元素的最小和。
 * @param  grid [description]
 * @return      [description]
 */
int minimumPathSumOfUniquePath::solution(vector<vector<int> > &grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > tmp(m,vector<int>(n));
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += grid[0][i];
		tmp[0][i] = sum;
	}
	sum = 0;
	for (int i = 0; i < m; ++i)
	{
		sum += grid[i][0];
		tmp[i][0] = sum;
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if(tmp[i-1][j] < tmp[i][j-1])
				tmp[i][j] = tmp[i-1][j]+grid[i][j];
			else
				tmp[i][j] = tmp[i][j-1]+grid[i][j];
		}
	}
	return tmp[m-1][n-1];
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}