#include <iostream>
using namespace std;

class max_heap
{
private:
	int *mHeap;
	int size;
public:
	max_heap(int A[],int n);
	void fliterUp();
	void fliterDown(int start,int end);
	void pop();
	~max_heap(){ }
};

max_heap::max_heap(int A[],int n)
{
	mHeap = A;
	size = n;
	fliterUp();
}


/*
 * 最大堆的向上调整算法(从start开始向上直到0，调整堆)
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
 */
void max_heap::fliterUp()
{
	for(int i=0;i<size;i++)
	{
		int c = i;
		int parent = (c-1)/2;
		int tmp = mHeap[c];
		while(c>0)
		{
			if(mHeap[c] <= mHeap[parent])
				break;
			else{
				mHeap[c] = mHeap[parent];
				mHeap[parent] = tmp;
				c = parent;
				parent = (c-1)/2;
			}
		}
	}
}

/* 
 * 最大堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
 void max_heap::fliterDown(int start,int end)
 {
 	int c = start;
 	int child = c*2+1;//左孩子
 	int tmp = mHeap[c];
 	while(child <= end)
 	{
 		//child u左孩子，child+1右孩子
 		if(child < end && mHeap[child] < mHeap[child+1])
 			child++;
 		if (mHeap[c]>=mHeap[child])
 		{
 			break;
 		}else{
 			mHeap[c] = mHeap[child];
 			mHeap[child] = tmp;
 			c = child;
 			child = 2*c+1;
 		}
 	}
 }

void max_heap::pop()
{
	int tmp = mHeap[0];
	mHeap[0] = mHeap[size-1];
	mHeap[size-1] = tmp;
	size = size-1;
	fliterDown(0, size-1);
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
	max_heap h(A,n);
	for(int i=0;i<n-1;i++)
		h.pop();
	printArray(A, n);
	return 0;
}