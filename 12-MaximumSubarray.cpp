/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (maxEnd is used for this). 
    And keep track of maximum sum contiguous segment among all positive segments (maxSoFar is used for this). 
    Each time we get a positive-sum compare it with maxSoFar and update maxSoFar if it is greater than maxSoFar.
    */
    int maxSubArray(vector<int>& nums) {
        int maxEnd = 0, maxSoFar = INT8_MIN;
        
        for(int i=0; i<nums.size(); i++){
            maxEnd += nums[i];
           
            if(maxSoFar < maxEnd)
                maxSoFar = maxEnd;
            
            if(maxEnd < 0)
                maxEnd = 0;
        }
        return maxSoFar;      
    }
};

int main()
{

    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << s.maxSubArray(nums) << endl;

    return 0;

}