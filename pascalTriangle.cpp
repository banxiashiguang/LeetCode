#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<vector<int> > &num)
{
	for (int i = 0; i < num.size(); ++i)
	{
		for (int j = 0; j < num[i].size(); ++j)
		{
			cout << num[i][j] << "\t";
		}
		cout << endl;
	}
}

class pascalTriangle
{
public:
	pascalTriangle() { }
	~pascalTriangle() { }
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > res;
		for (int i = 1; i <= numRows; ++i)
		{
			vector<int> tmp;
			tmp.push_back(1);
			for (int j = 0; j < i-2; ++j)
			{
				int size = res.size()-1;
				tmp.push_back(res[size][j]+res[size][j+1]);
			}
			if(i != 1)
				tmp.push_back(1);
			res.push_back(tmp);
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	pascalTriangle p;
	vector<vector<int> > res = p.generate(4);
	printVector(res);
	return 0;
}