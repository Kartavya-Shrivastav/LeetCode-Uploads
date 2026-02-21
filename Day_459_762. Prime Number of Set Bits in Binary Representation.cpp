#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their
binary representation.
Approach: We can iterate through each number in the range [left, right], count the number of set bits in its binary representation using the built-in
function __builtin_popcount, and check if that count is a prime number. If it is, we increment our count.

Steps:
1. Initialize a variable count to 0 to keep track of the count of numbers with a prime number of set bits.
2. Iterate through each number i from left to right (inclusive).    
    a. For each number i, count the number of set bits using __builtin_popcount(i).
    b. Check if the count of set bits is a prime number using the isPrime function.
    c. If it is prime, increment the count variable.    
3. After the loop, return the count variable.

Time Complexity: O(n * sqrt(m)) where n is the number of integers in the range [left, right] and m is the maximum number of set bits (which is at most 32 for 32-bit integers).
Space Complexity: O(1) since we are using only a constant amount of extra space.
*/

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);  // C++ built-in to count set bits
            if (isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
    
private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};