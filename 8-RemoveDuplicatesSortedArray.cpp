/*
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return nums.size();

    }
};

int main()
{

    Solution s;
    vector<int> nums = {1,1,2};
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};

    cout << s.removeDuplicates(nums) << endl;
    cout << s.removeDuplicates(nums2) << endl;

    return 0;

}