//注意：面积计算公式
#include <iostream>
#include <vector>

using namespace std;

class containerWithMostWater
{
public:
	containerWithMostWater() { }
	~containerWithMostWater() { }
	int area(vector<int> &height,int i,int j);
	int solution(vector<int> &height);
};

int containerWithMostWater::area(vector<int> &height,int i,int j)//计算面积
{
	return (min(height[i],height[j])*(j-i));
}

//暴力破解,时间复杂度O(n^2)
/*int containerWithMostWater::solution(vector<int> &height)
{
	int maxArea = 0;
	for(int i = 0;i < height.size();i++)
	{
		for(int j = i+1;j < height.size();j++)
			{
				int tmp = area(height,i,j);
				if(tmp > maxArea)
					maxArea = tmp;
			}
	}
	return maxArea;
}*/

int containerWithMostWater::solution(vector<int> &height)
{
	int left = 0;
	int right = height.size()-1;
	int maxArea = 0;
	while(left < right)
	{
		if(height[left] == 0)
		{
			left++;
			continue;
		}
		if(height[right] == 0)
		{
			right--;
			continue;
		}
		int tmp = area(height,left,right);
		if(tmp > maxArea)
			maxArea = tmp;
		if(height[left] < height[right])
			left++;
		else
			right--;
	}
	return maxArea;
}

int main(int argc, char const *argv[])
{
	int array[] = {1,2,4,3};
	int len = sizeof(array)/sizeof(int);
	vector<int> height(array,array+len);
	containerWithMostWater c;
	cout<<c.solution(height)<<endl;
	return 0;
}