#include <bits/stdc++.h>
using namespace std;

// Steps:
// 1. Handle edge cases such as zero numerator and negative signs.
// 2. Compute the integer part of the fraction and append it to the result string.
// 3. Use a map to track remainders and their positions in the result string to identify repeating cycles.
// 4. For each remainder, multiply by 10, compute the next digit, and update the remainder.
// 5. If a remainder repeats, insert parentheses to denote the repeating part.
// 6. Return the final result string.

// Time Complexity: O(n), where n is the number of digits in the fractional part before a repeat is detected.
// Space Complexity: O(n), for storing remainders in the map.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0"; // Zero numerator gives "0"

        string result;

        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0)) 
            result += '-';

        // Convert to long long to avoid overflow
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Append integer part
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result; // No fractional part

        result += '.'; // Start fractional part

        // Map to store remainder and its corresponding index in result
        unordered_map<long long, int> remainderIndex;

        while (remainder != 0) {
            // If this remainder has been seen before, we have a repeating cycle
            if (remainderIndex.count(remainder)) {
                result.insert(remainderIndex[remainder], "(");
                result += ')';
                break;
            }

            // Store the current remainder with its position
            remainderIndex[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};