#include <bits/stdc++.h>
using namespace std;

// Problem: 2300. Successful Pairs of Spells and Potions
// Approach: Frequency array and prefix sum to count successful pairs

// Steps:
// 1. Create a frequency array to count occurrences of each potion strength.
// 2. Compute the prefix sum of the frequency array to get counts of potions with strength less than or equal to each value.
// 3. For each spell, calculate the minimum required potion strength to achieve the success threshold.
// 4. Use the prefix sum array to determine how many potions meet or exceed this required strength.
// 5. Store the results in an output array and return it.
// 6. Return the array of counts of successful pairs for each spell.

// Time Complexity: O(n + m + pMax), where n is the number of spells, m is the number of potions, and pMax is the maximum potion strength.
// Space Complexity: O(pMax) for the frequency and prefix sum arrays.

class Solution {
public:
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001]={0}, pMax=0;
        for(int p: potions){
            freq[p]++;
            pMax=max(pMax, p);
        }

        partial_sum( freq, freq+pMax+1, freq);

        const int n=spells.size(), m=potions.size();
        vector<int> result(n, 0);
        
        for (int i=0; i<n; i++) {
            const int spell=spells[i];
            const long long k = (success+spell-1)/spell;
            if (k<=pMax) {
                result[i]=m-(k>=1?freq[k-1]:0);
            }
        }       
        return result;
    }
};