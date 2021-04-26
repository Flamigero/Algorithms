/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1 or s.size() == 0)
            return false;

        unordered_map<char, char> m;
        stack<char> stackChar;
        m['}'] = '{';
        m[']'] = '[';
        m[')'] = '(';

        for (int i = 0; i < s.size(); i++)
        {
            if(stackChar.size() > 0 && m.count(s[i]) > 0)
            {
                if(m[s[i]] == stackChar.top())
                    stackChar.pop();
                else
                    stackChar.push(s[i]);
                    
            }
            else
                stackChar.push(s[i]);
        }

        if(stackChar.size() == 0)
            return true;

        return false;
    }
};

int main()
{

    Solution s;

    cout << s.isValid("()") << endl;

    return 0;

}