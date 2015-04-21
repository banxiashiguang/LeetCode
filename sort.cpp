#include "sort.h"

void swap(int A[],int a,int b)
{
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}
void print_sort(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
}

/*直接插入排序思想：将无序序列中的一个或者几个记录，插入到有序的序列中。
  *主要思想：将第一个元素视作有序的，从第二个元素开始将待排序的元素插入到有序的序列中。
  *时间复杂度：最好情况下是O(n)，最坏和平均复杂度是O(n^2)。
  *稳定性：稳定排序。
  *空间复杂度：O(1)。
 */
void insertion_sort(int A[],int n)
{
	for(int i=1;i<n;i++)
	{
		int tmp = A[i];
		int index = i;
		for(int j=i-1;j>=0;j--)
		{
			if(tmp < A[j])
			{
				A[index] = A[j];
				index = j;
			}else
				break;
		}
		A[index] = tmp;
	}
	print_sort(A, n);
}


/*折半插入排序思想：折半插入与直接插入比较，当第i 个记录要插入到前i-1个记录序列时，可以利用折半查找方式确定插入位置，以减少比较次数。
		            折半查找明显减少了关键字的“比较”次数，单记录的移动次数不变，故时间复杂度仍为O(n^2)
  *时间复杂度：最好情况下是O(n)，最坏和平均复杂度是O(n^2)。
  *稳定性：稳定排序。
  *空间复杂度：O(1)。
 */
  void bin_insertion_sort(int A[],int n)
  {
  	for(int i=1;i<n;i++)
  	{
  		int tmp = A[i];
  		int left = 0;
  		int right = i-1;
  		while(left <= right)
  		{
  			int mid = (left+right)/2;
  			if(A[mid] < tmp)
  				left = mid+1;
  			else
  				right = mid-1;
  		}
  		for(int j=i-1;j>=left;j--)
  			A[j+1] = A[j];
  		A[left] = tmp;
  	}
  	print_sort(A, n);
  }

  /*冒泡排序思想：两两交换，每次得到一个最大值或者最小值
  *时间复杂度：最好情况下是O(n)，最坏和平均复杂度是O(n^2)。
  *稳定性：稳定排序。
  *空间复杂度：O(1)。
 */
void bubble_sort(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(A[j] > A[j+1])
				swap(A,j, j+1);
		}
	}
	print_sort(A, n);
}


  /*快速排序思想：从待排序的序列中选出一个枢纽(通常是地一个),凡是小于枢纽的都移动到枢纽之前，凡是大于枢纽的都移动到枢纽之后
  *时间复杂度：平均复杂度O(nlogn)，最坏复杂度O(N^2)——逆序排列。
  *稳定性：不稳定排序。
  *空间复杂度：O(1)。
 */
int partition(int A[],int start,int end)
{
	int left = start;
	int right = end;
	int tmp = A[start];
	int index = start;
	while(left < right)
	{
		while(A[right] >= tmp && left < right)
		{
			right--;
		}
		A[index] = A[right];
		index = right;
		while(A[left] < tmp && left < right)
			left++;
		A[index] = A[left];
		index = left;
	}
	A[index] = tmp;
	print_sort(A, end+1);
	return index;
}
void quick_sort(int A[],int left,int right)
{
	if(left >= right)
		return;
	int refer = partition(A, left, right);
	quick_sort(A, left, refer-1);
	quick_sort(A, refer+1, right);
}


  /*选择排序思想：每次找到最小(最大)的记录，并与相应的位置的元素进行交换。(注意与插入排序的区别：插入排序每次交换多次，而选择排序每次只交换一次)
  *时间复杂度：最大、最小、平均时间复杂度都是O(n^2)
  *稳定性：不稳定排序。
  *空间复杂度：O(nk+nlg(n/k))。
 */
  void selection_sort(int A[],int n)
  {
  	for(int i=0;i<n-1;i++)//如果A[1...n-1]已排序，且包含了A中最小的n-1个元素，则A[n]肯定是最大的，因此肯定是已排序的。
  	{
  		int minIndex = i;
  		for(int j=i+1;j<n;j++)
  		{
  			if(A[minIndex] > A[j])
  			{
  				minIndex = j;
  			}
  		}
  		swap(A, i, minIndex);
  	}
  	print_sort(A, n);
  }

  /*归并排序思想(以2-路归并为例)：将一个具有n个待排序记录的序列看成是n个长度为1的有序序列，然后进行两两归并，
   得到n/2个长度为2的有序序列，再进行两两归并，得到n/4个长度为4的有序序列，如此重复，直至得到一个长度为n的有序序列为止。
  *时间复杂度：最好和最坏的时间复杂度均为O(nlogn)。
  *稳定性：稳定排序。
  *空间复杂度：O(1)。
 */
void merge_array(int a[],int first,int mid,int last,int tmp[])
{
	int i = first;
	int j = mid+1;
	int k = 0;
	while(i<mid && j<last)
	{
		if(a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while(i <= mid)
		tmp[k++] = a[i++];
	while(j <= last)
		tmp[k++] = a[j++];
	for(int i=0;i<k;i++)
		a[first++] = tmp[i];
}
void merge_sort(int A[],int n,int k)
{
	
}

int main(int argc, char const *argv[])
{
	int A[] = {6,3,9,2,1,5,8,4,7};
	int n = sizeof(A)/sizeof(A[0]);
	//insertion_sort(A, n);
	//bin_insertion_sort(A, n);
	//bubble_sort(A, n);
	//quick_sort(A, 0, n-1);
	selection_sort(A, n);
	return 0;
}