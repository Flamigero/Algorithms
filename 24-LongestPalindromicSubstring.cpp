/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        vector<string> results;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            for (int j = i+1; j < s.size(); j++)
            {
                if(c == s[j])
                {
                    string temp = "";
                    temp = s.substr(i, j-i+1);
                    if(std::find(results.begin(), results.end(), temp) == results.end())
                    {
                        string tempReverse = temp;
                        reverse(tempReverse.begin(), tempReverse.end());
                        if(temp.size() > result.size() && temp == tempReverse) result=temp;
                        results.push_back(temp);
                    }
                } 
            }
            
        }

        if(result == "") return s.substr(0,1);
        return result;
    }

    string longestPalindrome2(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "ccc";

    cout << s.longestPalindrome2(str) << endl;

    return 0;
}