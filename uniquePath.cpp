#include <iostream>
#include <vector>
using namespace std;

class uniquePath
{
public:
	uniquePath() { }
	~uniquePath() { }
	int solution(int m,int n);
};

/**
 * 利用递归的方式，向左或者向下之后，重新当作问题，数组变成m*(n-1)或者(m-1)*n。
 * @param  m [description]
 * @param  n [description]
 * @return   [description]
 */
/*int uniquePath::solution(int m,int n)
{
	if(m == 1 || n == 1)
		return 1;
	int res;
	res = solution(m-1, n) + solution(m, n-1);
	return res;
}*/

/**
 * 利用动态规划:每个放个都可以选择(初始化为1),到达A[i][j]=A[i-1][j]+A[i][j-1]。
 * @param  m [description]
 * @param  n [description]
 * @return   [description]
 */
int uniquePath::solution(int m,int n)
{
	vector<vector<int> > tmp(m,vector<int>(n,1));//定义一个大小为m*n的vector对象,并初始化为1。
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			tmp[i][j] = tmp[i][j-1]+tmp[i-1][j];
		}
	}
	return tmp[m-1][n-1];
}
int main(int argc, char const *argv[])
{
	uniquePath u;
	cout << u.solution(23, 12) << endl;
	return 0;
}