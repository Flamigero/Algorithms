/*
Algorithm Sieve of Eratosthenes:
    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.

    return all i such that A[i] is true.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    void sieveOfEratosthenes(vector<int> &naturalNumbers) {
        int count_numbers = naturalNumbers.size();

        for (int i = 0; i < naturalNumbers.size(); i++)
        {
            if(pow(naturalNumbers[i], 2) > count_numbers) return;
            
            for (int j = i+1; j < naturalNumbers.size(); j++)
            {
                if(naturalNumbers[j]%naturalNumbers[i] == 0)
                    naturalNumbers.erase(naturalNumbers.begin() + j);
            }
            
        }
        
    }
};

int main()
{
    vector<int> naturalNumbers = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    Solution s;
    s.sieveOfEratosthenes(naturalNumbers);

    for (int i = 0; i < naturalNumbers.size(); i++)
    {
        cout << naturalNumbers[i] << " "; 
    }
    cout << endl;

    return 0;
}