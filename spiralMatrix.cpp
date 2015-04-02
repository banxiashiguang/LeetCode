//输出数组的螺旋序
#include <iostream>
#include <vector>
using namespace std;

class spiralMatrix
{
public:
	spiralMatrix() { }
	~spiralMatrix() { }
	vector<int> solution(vector<vector<int> > &matrix);
};

vector<int> spiralMatrix::solution(vector<vector<int> > &matrix)
{
	vector<int> res;
	if(matrix.size() == 0)
		return res;
	int m = 0;
	int n = 0;
	int colSum = matrix[0].size()-1;
	cout << "colSum=" << colSum << endl;
	int rowSum = matrix.size()-1;
	cout << "rowSum=" << rowSum << endl;
	for(int i = 0;i < (matrix.size()-1)/2+1;i++)
	{
		if(n <= colSum)
		{
			cout << "1-----------------------" << endl;
			for (int j = n; j <= colSum; ++j)
			{
				cout << matrix[m][j]<<"\t";
				res.push_back(matrix[m][j]);
			}
			cout << endl;
		}
		if(m+1 < rowSum)
		{
			cout <<"2-----------------------" << endl;
			for(int j = m+1;j < rowSum;j++)
			{
				cout << matrix[j][colSum] << "\t";
				res.push_back(matrix[j][colSum]);
			}
			cout << endl;
		}

		if(n <= colSum && m != rowSum)//解决类似于1*n问题
		{
			cout <<"3-----------------------" << endl;
			for(int j = colSum;j >= n;j--)
			{
				cout << matrix[rowSum][j] << "\t";
				res.push_back(matrix[rowSum][j]);
			}
			cout << endl;
		}
		if(m+1 < rowSum && n != colSum)//解决类似于n*1问题
		{
			cout <<"4-----------------------" << endl;
			for(int j= rowSum-1;j > m;j--)
			{
				cout << matrix[j][n] << "\t";
				res.push_back(matrix[j][n]);
			}
			cout << endl;
		}
		m++;
		n++;
		colSum--;
		rowSum--;
	}
	cout << "HHHH" << endl;
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > matrix = {{7},{9},{6}};
	spiralMatrix s;
	vector<int> res = s.solution(matrix);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << "\t";
	}
	cout << endl;
	return 0;
}