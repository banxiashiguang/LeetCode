#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix,int target)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		if(m == 0)
			return false;
		int left = 0;
		int right = m*n-1;
		while(left <= right)
		{
			int mid = (left+right) >> 1;
			int row = mid/n;
			int column = mid%n;
			cout << "left=" << left << "\t" << "right=" << right << "\t" << "mid=" << mid << endl;
			cout << "row=" << row << "\t" <<"column=" << column << endl;
			cout << matrix[row][column] << endl;
			if(matrix[row][column] == target)
				return true;
			else if(matrix[row][column] > target)
			{
				if(column == 0)
				{
					--row;
					right = (row*n)+(n-1);
				}else
					right = (row*n)+(column-1);
			}else{
				if(column == n-1)
				{
					++row;
					left = row*n;
				}else
					left = (row*n)+(column+1);
			}
		}
		return false;
	}
};

int main(int argc,const char *argv[])
{
	vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	Solution s;
	cout << s.searchMatrix(matrix,3) << endl;	
}
