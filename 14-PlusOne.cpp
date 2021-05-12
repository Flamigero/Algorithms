/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--)
        { 
            if(digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{

    Solution s;
    vector<int> digits {9};
    digits = s.plusOne(digits);

    for (int i = 0; i < digits.size(); i++)
    {
        cout << digits[i] << ", "; 
    }
    cout << endl;

    return 0;

}