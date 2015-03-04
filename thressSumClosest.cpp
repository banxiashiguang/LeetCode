#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits.h>
using namespace std;

class thressSumClosest
{
public:
	thressSumClosest() { }
	~thressSumClosest() { }
	int solution(vector<int> &num,int target);	
};

int thressSumClosest::solution(vector<int> &num,int target)
{
	sort(num.begin(),num.end());
	int size = num.size();
	int closest = INT_MAX;
	int left,right,sum;
	for(int i=0;i<size-2;i++)
	{
		left = i+1;
		right = size-1;
		while(left < right)
		{
			int differ = target-(num[i]+num[left]+num[right]);
			if(abs(differ) < closest)
			{
				closest = abs(differ);
				sum = num[i]+num[left]+num[right];
			}
			if(differ > 0)
			{
				left++;
			}else if(differ < 0){
				right--;
			}else{
				return sum;
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	thressSumClosest t;
	int array[] = {0,2,1,-3};
	vector<int> v(array,array+sizeof(array)/sizeof(array[0]));
	cout<<t.solution(v,1)<<endl;
	return 0;
}