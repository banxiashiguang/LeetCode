#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval(): start(0),end(0) { }
	Interval(int x,int y):start(x),end(0) { }
};

class insertInterval
{
public:
	insertInterval() { }
	~insertInterval() { }
	vector<Interval> solution(vector<Interval> &intervals,Interval newInterval);
};

vector<Interval> insertInterval::solution(vector<Interval> &intervals,Interval newInterval)
{
	vector<Interval> res;
    	if(intervals.size() == 0)
    	{
    	    res.push_back(newInterval);
    		return res;
    	}
    	int size = intervals.size();
    	int left = newInterval.start,right = newInterval.end;
    	bool flags = true;
    	for (int i = 0; i < size; ++i)
    	{
    		if(newInterval.end < intervals[i].start && flags)
    		{
    			flags = false;
    			res.push_back(newInterval);
    		}
    		if(newInterval.start > intervals[i].end || newInterval.end < intervals[i].start)
    			res.push_back(intervals[i]);
    		else{
    			if(intervals[i].start < newInterval.start)
    				left = intervals[i].start;
    			if(intervals[i].end > newInterval.end)
    				right = intervals[i].end;
    			newInterval.start = left;
    			newInterval.end = right;
    		}
    	}
    	if(newInterval.end >= intervals[size-1].end)
    	    res.push_back(newInterval);
    	return res;
}

int main(int argc, char const *argv[])
{
	return 0;
}