/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16
*/

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i; j < height.size(); j++)
            {
                int distance = j-i;
                int tempMax = 0;
                if(height[i] > height[j])
                    tempMax = height[j] * distance;
                else
                    tempMax = height[i] * distance;
                if(tempMax > max) max = tempMax;
            }
        }

        return max;
    }

    int maxArea2(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;          
        while(i < j){
            int distance = j - i;
            int minimum = min(height[i], height[j]);
            ans = max(ans, distance * minimum);
            height[i] > height[j] ? j-- : i++;  
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> height = {1,8,100,2,100,4,8,3,7};

    //cout << s.maxArea(height) << endl;
    cout << s.maxArea2(height) << endl;

    return 0;
}