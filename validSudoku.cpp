#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class validSudoku
{
public:
	validSudoku(){ }
	~validSudoku() { }
	bool solution(vector<vector<char> > &board);
};

bool validSudoku::solution(vector<vector<char> > &board)
{
	int row[9];//行
	int column[9];//列
	for(int i=0;i<9;i++)
	{
		memset(row,0,sizeof(int)*9);
		memset(column,0,sizeof(int)*9);
		for(int j=0;j<9;j++)
		{
			if(board[i][j] != '.')
			{
				if(row[board[i][j] - '1']>0)
					return false;
				else
					row[board[i][j] - '1']++;
			}
			if(board[j][i] != '.')
			{
				if(column[board[j][i] - '1'] > 0)
					return false;
				else
					column[board[j][i] - '1']++;
			}
		}
	}
	for(int i=0;i<9;i=i+3)
	{
		for(int j=0;j<9;j=j+3)
		{
			memset(row,0,sizeof(int)*9);
			for(int a=0;a<3;a++)
			{
				for(int b=0;b<3;b++)
				{
					if(board[a+i][b+j] != '.')
					{
						if(row[board[a+i][b+j] -'1'] > 0)
							return false;
						else
							row[board[a+i][b+j]-'1']++;
					}
				}
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	return 0;
}