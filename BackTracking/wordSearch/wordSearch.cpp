#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
	bool search(vector<vector<char> > &tmp,int i,int j,string word,int size)
	{
		if(i < 0 || j < 0 || i >= tmp.size() || j >= tmp[0].size() || tmp[i][j] == '#'|| tmp[i][j] != word[size])
			return false;
		if(size+1 == word.size())
			return true;
		char t = tmp[i][j];
		tmp[i][j] = '#';
		++size;
		if(search(tmp,i+1,j,word,size) || search(tmp,i-1,j,word,size) || search(tmp,i,j-1,word,size) || search(tmp,i,j+1,word,size))//搜索上下左右
			return true;
		tmp[i][j] = t;
		return false;
	}
	bool exist(vector<vector<char> > &board,string word)
	{
		for(int i = 0; i < board.size(); ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(search(board,i,j,word,0))
						return true;
			}
		}
		return false;
	}
};

int main(int argc,const char *argv[])
{
	vector<vector<char> > board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
	string word = "BCESEEEFS";
	Solution s;
	cout << s.exist(board,word) << endl;
	return 0;
}
