#include <iostream>
#include <vector>
using namespace std;
int main(int argc,const char *argv[])
{
	vector<vector<int>> A = {{1,2},{3,4},{5,6}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout << A[j][i] << "\t";
		}
		cout << endl;
	}
	return 0;
}
