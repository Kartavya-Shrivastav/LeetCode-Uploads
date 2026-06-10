/*
Problem: Given an array of positive integers nums, replace each number with the sum of its digits and return the minimum value among all the resulting digit sums.

Approach: For each number in the array, compute the sum of its digits by repeatedly extracting the last digit using the modulo operator and removing it using integer division. Track the minimum digit sum encountered during the traversal and return it at the end.

Steps:
1. Initialize a variable min_val with INT_MAX to store the minimum digit sum found so far.
2. Traverse each number in the nums array.
3. For the current number:
   - Initialize current_sum as 0.
   - Repeatedly extract the last digit using num % 10 and add it to current_sum.
   - Remove the last digit using num /= 10.
4. After calculating the digit sum, update min_val if current_sum is smaller.
5. After processing all numbers, return min_val.

Time Complexity: O(n × d), where n is the number of elements in nums and d is the maximum number of digits in any number. We process each digit of every number exactly once.

Space Complexity: O(1), as only a few variables are used regardless of the input size.
*/
class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int current_sum = 0;
            
            while (num > 0) {
                current_sum += num % 10;
                num /= 10;
            }
            
            min_val = min(min_val, current_sum);
        }
        
        return min_val;
    }
};