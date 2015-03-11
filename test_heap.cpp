#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
void printHeap(vector<int> &num)
{
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<"\t";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int a[] = {20,15,2,30,5,1,40};
	vector<int> tmp(a,a+sizeof(a)/sizeof(a[0]));

	make_heap(tmp.begin(),tmp.end());//默认建立大顶堆,，第三个参数决定建堆方式
	printHeap(tmp);

	pop_heap(tmp.begin(),tmp.end());//将front（即第一个最大元素）移动到end的前部，同时将剩下的元素重新构造成(堆排序)一个新的heap。
	tmp.pop_back();
	printHeap(tmp);

	tmp.push_back(99);
	push_heap(tmp.begin(),tmp.end());//对刚插入的（尾部）元素做堆排序。
	printHeap(tmp);

	sort_heap(tmp.begin(),tmp.end());//将一个堆做排序,最终成为一个有序的系列，可以看到sort_heap时，
					   //必须先是一个堆（两个特性：1、最大元素在第一个 2、添加或者删除元素以对数时间），因此必须先做一次make_heap.
	printHeap(tmp);
	return 0;
}
