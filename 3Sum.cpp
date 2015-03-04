#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class threeSum
{
public:
	threeSum() { }
	~threeSum() { }
	vector< vector<int> > solution(vector<int> &num);
	
};

vector< vector<int> > threeSum::solution(vector<int> &num)
{
	vector<vector<int> > res;
    	vector<int> tmp(3,0);
    	int number = num.size();
    	if(number < 3)
    	    return res;
    	int left,right;
    	sort(num.begin(),num.end());
    	for(int i=0;i<number;i++)
    		cout<<num[i]<<"\t";
    	cout<<endl;
    	int refer = num[0]-1;
    	for(int i=0;i<number-2;i++)
    	{
    		if(num[i] == refer)
    			continue;
    		left = i+1;
    		right = number-1;
    		while(left < right)
    		{
    			if((left > i+1) && (num[left-1] == num[left]))
    			{
    				left++;
    				continue;
    			}
    			if((right < number-1) && (num[right] == num[right+1]))
    			{
    				right--;
    				continue;
    			}
    			int sum = num[left]+num[right]+num[i];
    			if(sum == 0)
    			{
    				cout<<"i="<<i<<"\t";
    				cout<< num[i]<<"\t"<<num[left]<<"\t"<<num[right]<<endl;
	    			tmp[0] = num[i];
	    			tmp[1] = num[left];
	    			tmp[2] = num[right];
    				res.push_back(tmp);
    				left++;
    				right--;
    			}else if(sum > 0)
    			{
    				right--;
    			}else{
    				left++;
    			}
    		}
    		refer = num[i];
    	}
    	return res;
}

int main(int argc, char const *argv[])
{
	int a[] = {11,-8,9,-6,-10,14,-5,-10,2,-1,-14,-13,-5,9,-5,-12,9,5,-1,-4,-14,5,-11,3,6};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	threeSum t;
	t.solution(num);
	return 0;
}