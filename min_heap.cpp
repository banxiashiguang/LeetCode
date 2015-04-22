#include <iostream>
using namespace std;

class min_heap
{
private:
	int *mHeap;
	int mCapacity;
	int mSize;
public:
	min_heap(int A[],int n);
	~min_heap() { }
	void insert(int index);
	void fliterUp(int start);
	void pop();
	void fliterDown(int start,int end);
};

min_heap::min_heap(int A[],int n)
{
	mHeap = A;
	mCapacity = n;
	mSize = 0;
}

/* 
 * 最小堆向上调整算法
 *
 * 注：数组实现的堆中，第N个节点的父节点的索引是(N-1)/2。
 *
 * 参数说明：
 *     start -- 被上调节点的位置(一般为插入元素的位置)
 */
 void min_heap::fliterUp(int start)
 {
 	int c = start;
 	int parent = (c-1)/2;
 	int tmp = mHeap[c];
 	while(c>0)
 	{
 		if(mHeap[c]>=mHeap[parent])
 			break;
 		else{
 			mHeap[c] = mHeap[parent];
 			mHeap[parent] = tmp;
 			c = parent;
 			parent = (c-1)/2;
 		}
 	}
 }
 void min_heap::insert(int index)
 {
 	mSize = index;
 	fliterUp(mSize);
 }

 /* 
 * 最小堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */

 void min_heap::fliterDown(int start,int end)
 {
 	int c = start;
 	int child = 2*c +1;
 	int tmp = mHeap[c];
 	while(child<=end)
 	{
 		//存在右孩子的情况
 		if(child<end && mHeap[child]>mHeap[child+1])
 			child++;
 		if(mHeap[c]<=mHeap[child])
 			break;
 		else{
 			mHeap[c] = mHeap[child];
 			mHeap[child] = tmp;
 			c = child;
 			child = 2*c+1;
 		}
 	}
 }

 void min_heap::pop()
 {
 	int tmp = mHeap[0];
 	mHeap[0] = mHeap[mSize];
 	mHeap[mSize] = tmp;
 	mSize--;
 	fliterDown(0, mSize);
 }
void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
}

 int main(int argc, char const *argv[])
 {
 	int A[]  = {5,1,3,2,4,6,9,7,8};
	int n = sizeof(A)/sizeof(A[0]);
	min_heap h(A,n);
	for(int i=0;i<n;i++)
		h.insert(i);
	printArray(A, n);
	for(int i=0;i<n;i++)
		h.pop();
	printArray(A, n);
 	return 0;
 }
