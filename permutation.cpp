/*算法思路：
 *(1)n个元素的全排列=（n-1个元素的全排列）+（另一个元素作为前缀）；
 *(2)出口：如果只有一个元素的全排列，则说明已经排完，则输出数组；
 *(3)不断将每个元素放作第一个元素，然后将这个元素作为前缀，并将其余元素继续全排列，等到出口，出口出去后还需要还原数组；
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutation(int A[],int begin,int end)
{
	if(begin == end)
	{
		for(int i=0;i<=end;i++)
			cout<<A[i]<<"\t";
		cout<<endl;
	}else{
		for(int j=begin;j<=end;j++)
		{
			swap(&A[begin], &A[j]);//交换首元素
			permutation(A, begin+1, end);//除首元素外，其余全排列
			swap(&A[j], &A[begin]);//恢复数组位置
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3};
	int size = sizeof(A)/sizeof(A[0]);
	vector<int> tmp(A,A+size);
	permutation(A, 0, size-1);
	do{
		cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<endl;
	}while(next_permutation(tmp.begin(),tmp.end()));
	return 0;
}