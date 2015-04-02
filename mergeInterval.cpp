#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0) { }
	Interval(int x,int y):start(x),end(y) { }
};

bool cmp(const Interval &a,const Interval &b)
{
	return a.start < b.start;
}

class mergeInterval
{
public:
	mergeInterval() { }
	~mergeInterval() { }
	vector<Interval> solution(vector<Interval> &intervals);
};

vector<Interval> mergeInterval::solution(vector<Interval> &intervals)
{
	vector<Interval> res;
	if(intervals.size() == 0)
		return res;
	if(intervals.size() == 1)
	{
		res.push_back(intervals[0]);
		return res;
	}
	sort(intervals.begin(),intervals.end(),cmp);
	Interval tmp(intervals[0].start,intervals[0].end);
	for (int i = 0; i < intervals.size(); ++i)
	{
		cout << intervals[i].start << "\t" << intervals[i].end << endl;
	}
	bool flags = false;
	for (int i = 1; i < intervals.size(); ++i)
	{
		if(intervals[i].start > tmp.end)
		{
			res.push_back(tmp);
			tmp.start = intervals[i].start;
			tmp.end = intervals[i].end;
		}else{
			if(tmp.end < intervals[i].end)
			{
				tmp.end = intervals[i].end;
			}
		}
	}
	res.push_back(tmp);
	return res;
}


int main(int argc, char const *argv[])
{
	Interval tmp;
	vector<Interval> intervals;
	vector<Interval> res;
	while(cin >> tmp.start >> tmp.end)
		intervals.push_back(tmp);
	mergeInterval m;
	res = m.solution(intervals);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i].start << "\t" << res[i].end << endl;
	}
	return 0;
}