#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class twoSum
{
public:
	twoSum(vector<int> &number,int target);
	~twoSum() { }
	int solution(vector<int> &tmp);
private:
	vector<int> number;
	int target;
};

twoSum::twoSum(vector<int> &number,int target)
{
	this->number = number;
	this->target = target;
}

int twoSum::solution(vector<int> &tmp)
{
	vector<int> copy(number);
	sort(number.begin(),number.end());
	bool flags = false;
	bool flagOne = true;
	bool flagsTwo = true;
	int left = 0;
	int right = number.size()-1;
	int sum,value1=-1,value2=-1;
	while(!flags && (left < right))
	{
		sum = number[left]+number[right];
		if(sum == target)
		{
			flags = true;
			cout<<"number[left]="<<number[left]<<endl;
			cout<<"number[right]="<<number[right]<<endl;
			tmp[0] = number[left];
			tmp[1] = number[right];
		}else if(sum < target)
			left++;
		else
			right--;
	}
	for(int i = 0;i < copy.size();i++)
	{
		if(copy[i] == tmp[0] && flagOne)
		{
			flagOne = false;
			value1 = i+1;
		}
		else if(copy[i] == tmp[1] && flagsTwo)
		{
			flagsTwo = false;
			value2 = i+1;
		}
	}
	if(value1 > value2)
	{
		tmp[0] = value2;
		tmp[1] = value1;
	}else{
		tmp[0] = value1;
		tmp[1] = value2;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int array[] = {0,4,3,0};
	int len = (sizeof(array)/sizeof(array[0]));
	vector<int> a(array,array+len);
	vector<int> value(2,-1);
	int b = 0;
	twoSum t(a,b);
	t.solution(value);
	cout<<"index1="<<value[0]<<",index2="<<value[1]<<endl;
	return 0;
}