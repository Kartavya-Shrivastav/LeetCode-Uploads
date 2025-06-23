#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of k-Mirror Numbers
// Approach: Generate palindromic numbers in base 10 and check if they are also palindromic in base k. Sum the first n such numbers.

// Steps:
// 1. Create a function to generate palindromic numbers by mirroring digits.
// 2. Check if a number is palindromic in a given base by converting it to that base and checking the digits.
// 3. Iterate through potential palindromic numbers, checking each one in base k.
// 4. Sum the first n valid k-mirror numbers.

// Time Complexity: O(n * log(m)), where n is the number of k-mirror numbers to find and m is the maximum number generated.
// Space Complexity: O(1), as we are using a constant amount of space for calculations.

class Solution {
public:
    // Helper function to create a palindromic number in base 10.
    // If 'odd' is true, creates an odd-length palindrome; otherwise, even-length.
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10; // Skip the middle digit for odd-length palindromes
        while (x > 0) {
            num = num * 10 + x % 10; // Append the mirrored digit
            x /= 10;
        }
        return num;
    }

    // Checks if a number is a palindrome in the given base.
    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        // Convert number to the given base and store digits
        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }
        // Check if the digits form a palindrome
        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }

    // Main function to find the sum of the first n k-mirror numbers.
    long long kMirror(int k, int n) {
        long long sum = 0;
        // Generate palindromic numbers by increasing their length
        for (long long len = 1; n > 0; len *= 10) {
            // Generate odd-length palindromes
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
            // Generate even-length palindromes
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};