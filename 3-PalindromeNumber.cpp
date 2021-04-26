/*
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

Example 1:
Input: x = 121
Output: true
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        /// Convert to array
        string temp = to_string(x);
        int init = 0;
        int end = temp.size()-1;

        /// Check palindrome
        while(init < end)
        {
            if(temp[init] != temp[end]) return false;

            init++;
            end--;
        }

        return true;

    }

    /*
    Second idea would be reverting the number itself, and then compare the number with original number, if they are the same, 
    then the number is a palindrome. However, if the reversed number is larger than int.MAX\text{int.MAX}int.MAX, we will hit integer overflow problem.

    Following the thoughts based on the second idea, to avoid the overflow issue of the reverted number, 
    what if we only revert half of the int\text{int}int number? After all, the reverse of the last half of the palindrome should be the same as the first half of the number, 
    if the number is a palindrome.

    For example, if the input is 1221, if we can revert the last part of the number "1221" from "21" to "12", and compare it with the first half of the number "12", 
    since 12 is the same as 12, we know that the number is a palindrome.
    */
    bool isPalindrome2(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber/10;
    }
};

int main()
{

    Solution s;

    cout << s.isPalindrome2(1221) << endl;

    return 0;
}