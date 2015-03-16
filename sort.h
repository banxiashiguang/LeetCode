#include <iostream>
using namespace std;

void swap(int a,int b);
void print_sort(int A[],int n);
void insertion_sort(int A[],int n);//插入排序
void bin_insertion_sort(int A[],int n);//折半插入排序
void bubble_sort(int A[],int n);//冒泡排序
int partition(int A[],int start,int end);//分割函数
void quick_sort(int A[],int left,int right);//快速排序
void selection_sort(int A,int n);//选择排序
void merge_array(int a[],int first,int mid,int last,int tmp[]);//合并两个排序好的数组
void merge_sort(int A,int n,int k);//K路归并排序