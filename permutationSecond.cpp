/*算法思路：
 *(1)n个元素的全排列=（n-1个元素的全排列）+（另一个元素作为前缀）；
 *(2)出口：如果只有一个元素的全排列，则说明已经排完，则输出数组；
 *(3)不断将每个元素放作第一个元素，然后将这个元素作为前缀，并将其余元素继续全排列，等到出口，出口出去后还需要还原数组；
 */

#include <iostream>
#include <vector>
using namespace std;

class permutationSecond
{
public:
	permutationSecond() { }
	~permutationSecond() { }
	void swap(vector<int> &tmp,int a,int b);
	void permutation(vector<int> &num,int begin,int end);
	vector<vector<int> > solution(vector<int> &num);
private:
	vector<vector<int> > res;
};

void permutationSecond::swap(vector<int> &tmp,int a,int b)
{
	int t = tmp[a];
	tmp[a] = tmp[b];
	tmp[b] = t;
}

void permutationSecond::permutation(vector<int> &num,int begin,int end)
{
	if(begin == end)
	{
		res.push_back(num);
	}else{
		for(int i=begin;i<=end;i++)
		{
			swap(num,begin,i);//交换首元素
			permutation(num,begin+1,end);//除首元素之外,其余全排列
			swap(num,begin,i);//回复数列
		}
	}
}

vector<vector<int> > permutationSecond::solution(vector<int> &num)
{

	permutation(num,0,num.size()-1);
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3};
	int size = sizeof(A)/sizeof(A[0]);
	vector<int> tmp(A,A+size);
	permutationSecond p;
	vector<vector<int> > res = p.solution(tmp);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}