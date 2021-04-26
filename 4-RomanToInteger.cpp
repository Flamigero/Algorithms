/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
 which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int solution = 0;

        unordered_map<char, int> romanInt;
        romanInt['I'] = 1;
        romanInt['V'] = 5;
        romanInt['X'] = 10;
        romanInt['L'] = 50;
        romanInt['C'] = 100;
        romanInt['D'] = 500;
        romanInt['M'] = 1000;

        for (int i = 0; i < s.size(); i++)
        {
            int current = romanInt[s[i]];
            int next = romanInt[s[i+1]];

            if(current < next)
                solution -= current;
            else
                solution += current;
        }

        return solution;

    }
};

int main()
{

    Solution s;

    cout << s.romanToInt("MCMXCIV") << endl;

}