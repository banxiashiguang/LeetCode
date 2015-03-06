#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class fourSum
{
public:
	fourSum() { }
	~fourSum() { }
	vector<vector<int> > solution(vector<int> &num,int target);
};

vector<vector<int> > fourSum::solution(vector<int> &num,int target)
{
	sort(num.begin(),num.end());
	vector<vector<int> > res;
	int size =  num.size();
	for(int i=0;i<size-3;i++)
	{
		if(i > 0 && num[i] == num[i-1])
			continue;
		for(int j=i+1;j<size-2;j++)
		{
			if(j > i+1 && num[j] == num[j-1])
				continue;
			int left = j+1;
			int right = size-1;
			while(left < right)
			{
				if(left > j+1 && num[left] == num[left-1])
				{
					left++;
					continue;
				}
				if(right < size-1 && num[right] == num[right+1])
				{
					right--;
					continue;
				}
				int sum = num[i]+num[j]+num[left]+num[right];
				if(target == sum)
				{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[left]);
					tmp.push_back(num[right]);
					res.push_back(tmp);
					left++;
					right--;
				}else if(target > sum)
				{
					left++;
				}else{
					right--;
				}
			}
		}
	}
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<"\t";
		cout<<endl;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int a[] = {-1,-5,-5,-3,2,5,0,4};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	fourSum f;
	f.solution(num,-7);
	return 0;
}