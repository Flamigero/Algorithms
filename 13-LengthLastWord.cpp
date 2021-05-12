/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        vector<std::string> results(std::istream_iterator<std::string>{iss},std::istream_iterator<std::string>());

        if(results.size() == 0)
            return 0;

        string lastWord = results[results.size()-1];
        return lastWord.size();
    }
};

int main()
{

    Solution s;
    string str = " ";

    cout << s.lengthOfLastWord(str) << endl;

    return 0;

}