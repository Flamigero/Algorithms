/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }

        return nums.size();

    }
};

int main()
{

    Solution s;
    vector<int> nums = {3,2,2,3};
    int val = 3;

    cout << s.removeElement(nums, val) << endl;

    return 0;

}