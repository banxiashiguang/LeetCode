#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<bool> &v)
{
	for(auto i:v)
		cout << i << "\t";
	cout << endl;
}
class Solution
{
public:
	void setZeroes(vector<vector<int> > &matrix)
	{
		vector<bool> row(matrix.size(),false);
		vector<bool> column(matrix[0].size(),false);	
		for(int i = 0; i < matrix.size(); ++i)
		{
			for(int j = 0; j < matrix[i].size(); ++j)
			{
				if(matrix[i][j] == 0)
				{
					if(row[i] == false)
						row[i] = true;
					if(column[j] == false)
						column[j] = true;
				}
			}
		}
		printVector(row);
		printVector(column);	
		for(int i = 0; i < matrix.size(); ++i)
		{
			for(int j = 0; j < matrix[i].size(); ++j)
			{
				if(row[i] == true || column[j] == true)
					matrix[i][j] = 0;
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

int main(int argc,const char *argv[])
{
	vector<vector<int> > matrix = {{0,1}};
	Solution s;
	s.setZeroes(matrix);
	return 0;
}
