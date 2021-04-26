/*
Write a function to find the longest common prefix string 
amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPrefixBetweenTwoStrings(string first, string second)
    {

        string prefix;

        for (int i = 0; i < first.size(); i++)
        {
            if(first[i] == second[i])
                prefix += first[i];
            else
                break;   
        }

        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0)
            return "";

        if (strs.size() == 1)
            return strs[0];

        string prefix = "";
        string first = strs[0];
        string second = strs[1];

        prefix = getPrefixBetweenTwoStrings(first, second);

        for (int i = 0; i < strs.size(); i++)
        {
            int hasPrefix = strs[i].find(prefix);
            if(hasPrefix != 0)
                prefix = getPrefixBetweenTwoStrings(strs[i], prefix);

            if(prefix == "")
                break;
        }

        return prefix;

    }
};

int main()
{

    Solution s;
    vector<string> strs ={"flower","flow","flight"};

    cout << s.longestCommonPrefix(strs) << endl;

    return 0;

}