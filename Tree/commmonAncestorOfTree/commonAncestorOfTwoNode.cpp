#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:

	//默认index = 0时，是根节点。
	int depthOfTree(vector<string> &matrix,int index)
	{
		int depth = 0;
		while(index > 0)
		{
			int i = 0;
			for(i = 0; i <= index; ++i)
			{
				if(matrix[index][i] == '1')
				{
					++depth;
					break;
				}
			}
			index = i;
		}
		return depth;
	}
	int goUP(vector<string> &matrix,int index,int steps)
	{
		while(steps > 0)
		{
			int i = 0;
			for(i = 0; i <= index; ++i)
			{
				if(matrix[index][i] == '1')
					break;
			}
			index = i;
			--steps;	
		}
		return index + 1;
	}
	int commonAncestor(vector<string> &matrix,int indexA,int indexB)
	{
		if(matrix[indexA-1][indexB-1] == '1')
			return min(indexA,indexB);
		int depthA = depthOfTree(matrix,indexA-1);
		int depthB = depthOfTree(matrix,indexB-1);
		cout << "depthA=" << depthA << "\t" << "depthB=" << depthB << endl;
		int maxNode = depthA > depthB? indexA:indexB;
		int steps = depthA > depthB? depthA-depthB:depthB-depthA;
		cout << "steps=" << steps << "\t" << "maxNode=" << maxNode << endl;
		int tmpNode1 = goUP(matrix,maxNode-1,steps);
		int tmpNode2 = maxNode == indexA? indexB:indexA; 
		cout << "tmpNode1=" << tmpNode1 << "\t" << "tmpNode2=" << tmpNode2 << endl;
		int minDepth = depthA < depthB? depthA:depthB;
		cout << "minDetpth=" << minDepth << endl;
		while(minDepth > 0)
		{
			int i = 0,j = 0;
			for(i = 0; i < tmpNode1; ++i)
			{
				if(matrix[tmpNode1-1][i] == '1')
					break;
			}
			for(j = 0; j < tmpNode2; ++j)
				if(matrix[tmpNode2-1][j] == '1')
					break;
			cout << "i=" << i << "j=" << j << endl;
			if(i == j)
				return i + 1;	
			else{
				tmpNode1 = i + 1;
				tmpNode2 = j + 1;
			}
		}
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line,str;
	int indexA,indexB;
	while(getline(cin,line))
	{
		vector<string> matrix;
		cout << "测试用例-----------------------" << endl;
		istringstream sin(line);
		while(sin >> str)
		{
			matrix.push_back(str);
		}
		getline(cin,line);
		istringstream ssin(line);
		ssin >> indexA >> indexB;
		cout << indexA << "\t" << indexB << endl;
		cout << s.commonAncestor(matrix,indexA,indexB) << endl;
		cout << endl;
	}
}
