#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

class reverseInteger
{
public:
	reverseInteger() { }
	~reverseInteger() { }
	int solution(int x);
};

int reverseInteger::solution(int x)
{
	int temp = 0;
	int value = 0;
            	temp = x;
        	while(temp != 0){
            		if(value > INT_MAX / 10 || value < INT_MIN / 10) {
                		return 0;
           		 }
           		value *= 10;
            		value += temp % 10;
            		temp = temp/10;
       	}
        return value;
}

int main(int argc, char const *argv[])
{
	int x =-123;
	reverseInteger r;
	cout<<r.solution(x)<<endl;
	return 0;
}