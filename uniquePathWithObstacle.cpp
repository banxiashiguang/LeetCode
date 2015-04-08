#include <iostream>
#include <vector>
using namespace std;

class uniquePathWithObstacle
{
public:
	uniquePathWithObstacle() { }
	~uniquePathWithObstacle() { }
	int solution(vector<vector<int> > &obstacleGrid);
};

int uniquePathWithObstacle::solution(vector<vector<int> > &obstacleGrid)
{
	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	vector<vector<int> > tmp(m,vector<int>(n,1));
    	for (int i = 0; i < n; ++i)
    	{
    		if(obstacleGrid[0][i] == 1)
    		{
    			int index = i;
    			while(index < n)
    				tmp[0][index++] = 0;
    			break;
    		}
    	}
    	for (int i = 0; i < m; ++i)
    	{
    		if(obstacleGrid[i][0] == 1)
    		{
    			int index = i;
    			while(index < m)
    				tmp[index++][0] = 0;
    			break;
    		}
    	}
    	for (int i = 1; i < m; ++i)
    	{
    		for (int j = 1; j < n; ++j)
    		{
    			if(obstacleGrid[i][j] == 1)
    				tmp[i][j] = 0;
    		}
    	}
    	for (int i = 1; i < m; ++i)
    	{
    		for (int j = 1; j < n; ++j)
    		{
    		    if(tmp[i][j] != 0)
    			    tmp[i][j] = tmp[i-1][j]+tmp[i][j-1];
    		}
    	}
    	return tmp[m-1][n-1];
}

int main(int argc, const char *argv[])
{
	vector<vector<int> > obstacleGrid{{0,0},{0,1}};
	uniquePathWithObstacle u;
	cout << u.solution(obstacleGrid) << endl;
	return 0;
}