#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the difference between the maximum and minimum numbers
    // that can be obtained by remapping a single digit in num
    int minMaxDifference(int num) {
        const string s = to_string(num);
        // Find the first digit that is not '9' to maximize the number
        const char to9 = s[firstNotNineIndex(s)];
        // Use the first digit to minimize the number
        const char to0 = s[0];
        return getMax(s, to9) - getMin(s, to0);
    }

private:
    // Returns the index of the first digit in s that is not '9'
    int firstNotNineIndex(const string& s) {
        for (int i = 0; i < s.length(); ++i)
            if (s[i] != '9')
                return i;
        return 0; // If all digits are '9', return 0
    }

    // Returns the integer after replacing all occurrences of to9 with '9'
    int getMax(string s, char to9) {
        for (char& c : s)
            if (c == to9)
                c = '9';
        return stoi(s);
    }

    // Returns the integer after replacing all occurrences of to0 with '0'
    int getMin(string s, char to0) {
        for (char& c : s)
            if (c == to0)
                c = '0';
        return stoi(s);
    }
};