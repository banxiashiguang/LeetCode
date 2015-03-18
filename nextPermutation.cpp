/*解题思路：1、从右往左扫描，找到前一个(index)比后一个大的数(p)。
 	          2、在末尾到p中，找到第一个比index大的数(j)。
 	          3、交换index和j。
 	          4、p到末尾反转。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class nextPermutation
{
public:
	nextPermutation() { }
	~nextPermutation(){ }
	void swap(vector<int> &num,int a,int b);
	void solution(vector<int> &num);
};

void nextPermutation::swap(vector<int> &num,int a,int b)
{
	int tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}
void nextPermutation::solution(vector<int> &num)
{
	if(num.size()<2)
		return;
	int index = num.size()-2;
	while(index >=0)
	{
		if(num[index]<num[index+1])
			break;
		else
			index--;
	}
	if(index>=0)
	{
		int j;
		for(j=num.size()-1;j>index;j--)
		{
			if(num[j]>num[index])
				break;
		}
		cout<<index<<"\t"<<j<<endl;
		swap(num,index,j);
		reverse(num.begin()+index+1,num.end());//index下一个，到end反转
	}else{
		reverse(num.begin(),num.end());
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {2,3,1};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	nextPermutation n;
	n.solution(num);
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<"\t";
	cout<<endl;
	return 0;
}