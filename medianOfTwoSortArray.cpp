#include <iostream>
#include <iomanip>
using namespace std;

class medianOfTwoSortArray
{
public:
	medianOfTwoSortArray() { }
	~medianOfTwoSortArray() { }
	double solution(int A[],int m,int B[],int n); 
};

//直接遍历，复杂度O(m+n)
/*double medianOfTwoSortArray::solution(int A[],int m,int B[],int n)
{
	int i = 0,j = 0,median = m+n;
	double prev = 0,last = 0;
	if(median < 2)
	{
		if(m == 0 && n ==0)
			return 0;
		else if(m ==1 && n ==0)
			return A[0];
		else
			return B[0];
	}
	while((i+j) <= (median/2))
	{
		prev = last;
		if(i >= m)
		{
			last = B[i];
			i++;	
		}else if(j >= m)
		{
			last = A[j];
			j++;
		}else if(A[i] < B[j])
		{
			last = A[i];
			i++;
		}else{
			last = B[j];
			j++;
		}
	}
	if(median %2 == 0)
		return (prev + last)/2;
	else
		return last;
}*/

//二分法遍历，时间复杂度为log(m+n)
double findKth(int a[],int m,int b[],int n,int k)
{
	if(m > n)
		return findKth(b, n, a, m, k);
	if(m == 0)
		return b[k-1];
	if(k == 1)
		return min(a[0],b[0]);

	int pa = min(m,k/2);
	int pb = k-pa;
	if(a[pa-1] < b[pb-1])
		return findKth(a+pa, m-pa, b, n, k-pa);
	else if(a[pa-1] > b[pb-1])
		return findKth(a, m, b+pb, n-pb, k-pb);
	else
		return a[pa-1];
}
double medianOfTwoSortArray::solution(int A[],int m,int B[],int n)
{
	int total = m + n;
	if (total%2 == 1)
		return findKth(A, m, B, n, total / 2 + 1);
	else
	{
		double sum1 = ((double)(findKth(A, m, B, n, total / 2)))/2;
		double sum2 = ((double)(findKth(A, m, B, n, total / 2 + 1)))/2;
		return (sum1+sum2);
	 }
}

int main(int argc, char const *argv[])
{
	int A[]={100001};
	int B[]={100000};
	medianOfTwoSortArray m;
	cout<<fixed<<setprecision(4)<<m.solution(A, 1, B, 1)<<endl;
	return 0;
}