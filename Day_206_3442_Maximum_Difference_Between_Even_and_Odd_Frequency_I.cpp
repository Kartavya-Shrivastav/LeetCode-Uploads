#include <bits/stdc++.h>
using namespace std;

// Class to find the maximum difference between the highest and lowest frequency of characters in a string

class Solution {
public:
    // Function to find the maximum difference between the highest odd frequency
    // and the lowest even frequency of characters in the string
    int maxDifference(string s) {
        vector<int> mpp(26); // Frequency map for each lowercase letter
        int maxi = 0, mini = s.size(); // Initialize max odd and min even frequencies
        for (char c : s) mpp[c - 'a']++; // Count frequency of each character
        for (int i = 0 ; i < 26; i++) {
            if (mpp[i] % 2 != 0) // If frequency is odd
                maxi = max(maxi, mpp[i]);
            if (mpp[i] % 2 == 0 && mpp[i] > 0) // If frequency is even and non-zero
                mini = min(mini, mpp[i]);
        } 
        return maxi - mini; // Return the difference
    }
};
