/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 
32-bit integer range [-231, 231 - 1], then return 0.

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321
*/

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        int t = abs(x);
        queue<int> queue;
        double solution = 0;

        while (t > 0)
        {
            queue.push(t%10);
            t = t/10;
        }

        for (int i = queue.size()-1;!queue.empty(); i--)
        {
            double pows = pow(10, i);
            double temp;

            if(pows > 0)
            {
                temp = pows * queue.front();
                if(temp > 2147483647)
                    return 0;
            }
            else
                temp = queue.front();
            
            solution += temp;

            queue.pop();
        }

        if(solution > 2147483647)
            return 0;

        if(x < 0)
            return solution * -1;

        return solution;

    }

    int reverse2(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > 2147483647/10 || (rev == 2147483647 / 10 && pop > 7)) return 0;
            if (rev < -2147483647/10 || (rev == -2147483647 / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{

    Solution s;
    cout << s.reverse2(123) << endl;

    return 0;

}