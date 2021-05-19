/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
The number of elements initialized in nums1 and nums2 are m and n respectively. 
You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while (i<m && j<n)
        {
            if(nums1[i] <= nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        if(j==n) ans.insert(ans.end(), nums1.begin()+i, nums1.begin()+m);
        else ans.insert(ans.end(), nums2.begin()+j, nums2.begin()+n);

        nums1 = ans;
    }
};

int main()
{

    Solution s;
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;

}