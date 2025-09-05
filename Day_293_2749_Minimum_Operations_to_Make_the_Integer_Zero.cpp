#include<bits/stdc++.h>
using namespace std;

// Problem: Given two integers num1 and num2, determine the minimum number of operations required to reduce num1 to zero.
//          In each operation, you can subtract num2 from num1 and then divide num1

// Approach: Iterate through possible operation counts, calculating the remaining value after each operation.
//           Count the number of set bits in the remaining value to check if it can be reduced to zero with the given operations.

// Steps:
// 1. Loop through possible operation counts from 1 to 60.
// 2. For each operation count, calculate the remaining value after subtracting num2 multiplied by the operation count from num1.
// 3. If the remaining value is less than the operation count, continue to the next iteration.
// 4. Count the number of set bits in the remaining value.
// 5. If the number of set bits is less than or equal to the operation count, return the operation count.
// 6. If no valid operation count is found, return -1.

// Time Complexity: O(60 * log(num1)) due to the loop and bit counting.
// Space Complexity: O(1)

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long remaining=num1-1LL * i*num2;
            if(remaining<i) continue;

            int ones=0;
            long long temp=remaining;
            while(temp>0){
                ones+=(temp & 1);
                temp>>=1;
            }
            if(ones<=i) return i;
        }
        return -1;

    }
};