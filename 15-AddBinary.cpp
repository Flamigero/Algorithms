/*
Given two binary strings a and b, return their sum as a binary string

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aSize = a.size();
        int bSize = b.size();
        string strReturn = "";

        unordered_map<string, string> posibleResults;
        posibleResults["00"] = "0";
        posibleResults["01"] = "1";
        posibleResults["10"] = "1";
        posibleResults["11"] = "0";
        posibleResults["111"] = "1";
        posibleResults["110"] = "0";
        posibleResults["101"] = "0";
        posibleResults["011"] = "0";
        posibleResults["100"] = "1";
        posibleResults["010"] = "1";
        posibleResults["001"] = "1";

        bool addOne = false;
        while(a.size() > 0 && b.size() > 0)
        {
            string sum;
            sum.push_back(a.back());
            sum.push_back(b.back());
            if(addOne) sum.push_back('1');
            strReturn.insert(0, posibleResults[sum]);
            if(count(sum.begin(), sum.end(), '1') >= 2) addOne = true;
            else addOne = false;
            a = a.substr(0, a.size()-1);
            b = b.substr(0, b.size()-1);
        }

        string lastString;
        if(a.size() > 0) lastString = a;
        else lastString = b;

        for (int i = lastString.size()-1; i >= 0; i--)
        {
            string sum;
            sum.push_back(lastString[i]);
            if(addOne) sum.push_back('1');
            else sum.push_back('0');

            strReturn.insert(0, posibleResults[sum]);
            if(sum == "11") addOne = true;
            else addOne = false;
        }

        if(addOne) strReturn.insert(0, "1");

        return strReturn;
    }

    string addBinary2(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0 && a[i--] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;
            result.insert(0, 1, carry % 2 == 1 ? '1' : '0');
            carry /= 2;
        }
        
        return result;
    }
};

int main()
{

    Solution s;
    string a = "11", b = "1";

    cout << s.addBinary2(a, b) << endl;

    return 0;

}