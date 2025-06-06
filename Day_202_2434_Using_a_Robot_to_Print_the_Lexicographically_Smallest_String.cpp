#include<bits/stdc++.h>
using namespace std;
// This code defines a function to use a robot to print the lexicographically smallest string
// by processing characters from a given string and using a stack to manage the order of characters.


class Solution {
public:
    // Helper function to find the lexicographically smallest remaining character
    char l(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i]) return 'a' + i; // Return the first character with non-zero frequency
        }
        return 'a'; // Default return (should not be reached)
    }

    string robotWithString(string s) {
        stack<char> st; // Stack to simulate the robot's holding area
        string t = ""; // Result string
        vector<int> freq(26); // Frequency array for each character

        // Count frequency of each character in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Iterate over each character in s
        for (char ch : s) {
            st.push(ch); // Push current character to stack
            freq[ch - 'a']--; // Decrement its frequency

            // Pop from stack to result if stack top ≤ smallest remaining char
            while (!st.empty() && st.top() <= l(freq)) {
                t += st.top(); // Add top of stack to result
                st.pop(); // Remove from stack
            }
        }

        // Pop any remaining characters from the stack to the result
        while (!st.empty()) {
            t += st.top();
            st.pop();
        }

        return t; // Return the lexicographically smallest string
    }
};