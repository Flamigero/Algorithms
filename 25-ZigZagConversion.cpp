/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string answer = "";
        vector<string> rows (min(numRows, int(s.size())));
        int numRow = 0;
        bool goingDown = true;
        numRows -= 1;

        for(char c : s)
        {
            rows[numRow] += c;

            if(numRow==numRows) goingDown = false;
            if(numRow==0) goingDown = true;

            if(goingDown) numRow++;
            else numRow--;
        }

        for(string row : rows)
        {
            answer += row;
        }

        return answer;
    }
};

int main()
{
    Solution s;
    string str = "Carlos";

    cout << s.convert(str, 3) << endl;

    return 0;
}