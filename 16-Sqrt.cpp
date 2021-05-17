/*
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Example 1:
Input: x = 4
Output: 2
*/
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }

    int mySqrt2(int x)
    {
        long long s=0, e=x, ans, mid;   //long long due to some of test cases overflows integer limit.
        while(s<=e){             
            mid=(s+e)/2;
            if(mid*mid==x) return mid;     //if the 'mid' value ever gives the result, we simply return it.
            else if(mid*mid<x){             
                s=mid+1;        //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans=mid;        //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }
            else e=mid-1;       //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
        }
        return ans; 
    }
};

int main()
{
    Solution s;
    int x = 4;

    cout << s.mySqrt(4) << endl;

    return 0;
}