#include <bits/stdc++.h>
using namespace std;

// Problem: There are n bulbs that are initially off. You first turn on all the bulbs. Then, you toggle every second bulb (turning off bulbs 2, 4, 6, ...). On the third round, you toggle every third bulb (turning on bulbs 3, 6, 9, ...). This process continues for n rounds. After n rounds, return the number of bulbs that are on.
// Approach: The bulbs that remain on are those at positions that are perfect squares (1, 4, 9, 16, ...). This is because only perfect square numbers have an odd number of divisors. Thus, the number of bulbs that remain on after n rounds is equal to the number of perfect squares less than or equal to n.

// Sol 1: Calculate the number of perfect squares less than or equal to n using for loop till n.
// Steps: 1. Initialize a count variable to 0.
//        2. Loop through numbers from 1 to n.
//        3. For each number, check if it is a perfect square by comparing it to the square of its integer square root.
//        4. If it is a perfect square, increment the count.
//        5. Return the count.

// Sol 2: The number of perfect squares less than or equal to n is given by the largest integer k such that k*k <= n, which is simply the integer part of the square root of n.
// Steps: 1. Return the integer part of the square root of n using the sqrt function.


class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;

        int count = 0;
        for(int i=1; i<=n; i++){
            if(i == (int)sqrt(i) * (int)sqrt(i)){
                cout << i << " ";
                count++;
            }
        }

        return count;
    }
};

// OR

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
