/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> solution;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if(i != j)
                {
                    int ans = nums[i] + nums[j];

                    if(ans == target)
                    {
                        solution.push_back(i);
                        solution.push_back(j);
                        return solution;
                    }

                }
            }
            
        }
        
        return solution;

    }

    vector<int> twoSum2(vector<int>& nums, int target)
    {

        vector<int> solution;
        unordered_map<int, int> myMap;

        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target-nums[i];

            if(myMap.count(temp) > 0 && i != myMap[temp])
            {
                solution.push_back(i);
                solution.push_back(myMap.at(temp));

                return solution;
            }
        }

        return solution;
        
    }
};

int main()
{

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    Solution s;
    vector<int> ans = s.twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    ans = s.twoSum2(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;

}