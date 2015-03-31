#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class permutationDuplicates
{
private:
	vector<vector<int> > res;
	set<vector<int> > curRe;
public:
	permutationDuplicates() { }
	~permutationDuplicates(){ }
	void swap(vector<int> &num,int a,int b);
	void permutation(vector<int> &num,int begin,int end);
	vector<vector<int> > solution(vector<int> &num);
};

void permutationDuplicates::swap(vector<int> &num,int a,int b)
{
	int tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}

void permutationDuplicates::permutation(vector<int> &num,int begin,int end)
{
	if(begin == end)
		curRe.insert(num);
	else{
		for(int i=begin;i<=end;i++)
		{
			if((i > begin) && (num[i-1] == num[i]))
				continue;
			else{
				swap(num,begin,i);
				permutation(num,begin+1,end);
				swap(num,begin,i);
			}
		}
	}
}

vector<vector<int> > permutationDuplicates::solution(vector<int> &num)
{
	sort(num.begin(),num.end());
	permutation(num,0,num.size()-1);
	res.assign(curRe.begin(),curRe.end());
	return res;
}
int main(int argc, char const *argv[])
{
	int A[] = {1,3,2};
	int size = sizeof(A)/sizeof(A[0]);
	vector<int> tmp(A,A+size);
	permutationDuplicates p;
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