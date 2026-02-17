#include <bits/stdc++.h>
using namespace std;

// Problem: Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the binary watch could represent.
// Approach: A binary watch has 10 LEDs, where the first 4 represent the hours (0-11) and the last 6 represent the minutes (0-59). We can use a bit manipulation technique to generate all possible combinations of LEDs that are on. We will iterate through all possible combinations of LEDs (from 0 to 1023, which is 2^10 - 1) and check if the number of LEDs that are on matches n. If it does, we will convert that combination into a valid time format and add it to our result list.

// Steps:
// 1. Check if n is 0, if so return ["0:00"].
// 2. Check if n is greater than 8, if so return an empty list since it's not possible to have more than 8 LEDs on.
// 3. Initialize an empty result list and a variable q to represent the current combination of LEDs, starting with the smallest combination of n LEDs on (which is (1 << n) - 1).
// 4. Use a while loop to iterate through all combinations of LEDs until q is less than 1024 (which is 2^10).
// 5. Inside the loop, check if the current combination q represents a valid time using the isValid function. If it does, add the formatted time string to the result list.
// 6. To generate the next combination of n LEDs on, we can use the following bit manipulation technique:
//    - Calculate r as the rightmost set bit of q using q & -q.
//    - Calculate n as the next combination by adding r to q.
//    - Update q to the next combination using the formula: q = (((n ^ q) >> 2) / r) | n.
// 7. After the loop, return the result list containing all valid time combinations.

// Time Complexity: O(1) since we are generating a fixed number of combinations (at most 1024).
// Space Complexity: O(1) for the result list since the maximum number of valid times is limited (720 valid times for a binary watch).

class Solution {
public:
    vector<string> readBinaryWatch(int k) {
        if (k == 0) return {"0:00"};
        if (k > 8) return {};

        vector<string> res;
        int q = (1 << k) - 1;

        while (q < (1 << 10)) {
            string time = isValid(q);
            if (!time.empty()) res.push_back(time);
            int r = q & -q;
            int n = q + r;
            q = (((n ^ q) >> 2) / r) | n;
        }
        return res;
    }

    string isValid(int q) {
        int hour = q >> 6;
        int min = q & 63;
        if (hour >= 12 || min >= 60) return "";
        return to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min);
    }
};