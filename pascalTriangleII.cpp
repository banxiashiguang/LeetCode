#include <iostream>
#include <vector>
using namespace std;

class pascalTriangleII
{
public:
	pascalTriangleII() { }
	~pascalTriangleII() { }
	vector<int> getRow(int rowIndex)
	{
		vector<vector<int> > res;
		for (int i = 0; i <= rowIndex; ++i)
		{
			vector<int> tmp;
			tmp.push_back(1);
			for (int j = 0; j < i-1; ++j)
			{
				int size = res.size()-1;
				tmp.push_back(res[size][j]+res[size][j+1]);
			}
			if(i != 0)
				tmp.push_back(1);
			res.push_back(tmp);
		}
		return res[res.size()-1];
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}