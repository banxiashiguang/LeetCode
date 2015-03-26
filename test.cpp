#include <iostream>
using namespace std;

void fun()
{
	int a;//
	cout<<a<<endl;
}

int a;

int main(int argc, char const *argv[])
{
	fun();
	cout<<a<<endl;
	cout<<sizeof(char *)<<endl;
	cout<<sizeof(int *)<<endl;
	return 0;
}