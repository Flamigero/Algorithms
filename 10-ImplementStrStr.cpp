/*
Implement strStr().
Return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;

        if(needle.size() > haystack.size())
            return -1;

        for (int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                bool equal = true;
                for (int j = 0; j < needle.size(); j++)
                {
                    if(i+j > haystack.size())
                        return -1;
                    if(haystack[i+j] != needle[j])
                        equal = false;
                }
                if(equal) return i;
            }
        }
        
        return -1;
    }

    int strStr2(string haystack, string needle) 
    {
        /*METHOD 1
        
        if(needle == "")
            return 0;
        
        return haystack.find(needle);  */
        
        //METHOD 2
        int M = needle.length();
        int N = haystack.length();


        for (int i = 0; i <= N - M; i++) 
        {
            int j;
            for ( j = 0; j < M; j++)
                if (haystack[i + j] != needle[j])
                    break;

            if (j == M)
                return i;
        }

        return -1; 
        
    }
};

int main()
{

    Solution s;
    string haystack = "hello";
    string needle = "ll";

    cout << s.strStr(haystack, needle) << endl;

    return 0;

}