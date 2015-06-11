#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//利用vector实现MinStack
class MinStack {
private:
	vector<int> value;
	int min;
public:
	MinStack():min(numeric_limits<int>::max()) { }
	void push(int x) {
		if(x < min)
			min = x;
		value.push_back(x);
	}
	void pop() {
		if(value.size() > 0) {
			int tmp = value[value.size()-1];
			value.pop_back();
			if(min == tmp) {
				int len = value.size();
				if(len > 0) {
					min = value[0];
					for(int i = 1; i < len; ++i) {
						if(value[i] < min)
							min = value[i];
					}
				}else{
					min = numeric_limits<int>::max();
				}
			}
		}
	}
	int top() {
		return value[value.size()-1];
	}
	int getMin() {
		return min;
	}
};

int main(int argc,const char *argv[])
{
	MinStack stack;
	vector<int> value{6,2,4,9,1,8,3};
	for(auto i:value) {
		stack.push(i);
		cout << stack.top() << "\t" << stack.getMin() << endl;
	}
	for(int i = 0; i < value.size(); ++i) {
		stack.pop();
		cout << stack.top() << "\t" << stack.getMin() << endl;
	}
	return 0;
}
