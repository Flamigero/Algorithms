/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size() - 1;
        
        while (start <= end)
        {
            int mid = mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid - 1; 
            else
                start = mid + 1; 
        }

        return start;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {1,3};
    int target = 0;
    vector<int> nums2 = {1,3,5,6};
    int target2 = 4;

    cout << s.searchInsert(nums2, target2) << endl;

    return 0;

}