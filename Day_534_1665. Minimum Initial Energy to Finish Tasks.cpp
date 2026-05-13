#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 2D integer array tasks where tasks[i] = [actuali, minimumi] indicates that the ith task will consume actuali energy and requires at least minimumi energy to be performed. You can finish the tasks in any order you like. Return the minimum initial energy required to finish all the tasks. 
Approach: We can solve this problem by sorting the tasks based on the difference between the minimum energy required and the actual energy consumed. This way, we can ensure that we always perform the task that has the largest gap first, which helps in minimizing the initial energy required. 

Steps:
1. Sort the tasks in descending order based on the difference (minimumi - actuali).
2. Initialize two variables, ans and energy, to 0. ans will store the minimum initial energy required, and energy will keep track of the current energy level.
3. Iterate through the sorted tasks:
   a. For each task, check if the current energy is less than the minimum energy required for that task. If it is, increase the initial energy (ans) by the difference (minimumi - energy) and update the current energy to the minimum energy required.
   b. Subtract the actual energy consumed by the task from the current energy.  
4. After iterating through all the tasks, return the value of ans, which will be the minimum initial energy required to finish all the tasks.

Time Complexity: O(n log n), where n is the number of tasks, due to the sorting step. The rest of the operations are O(n) for iterating through the tasks. Space Complexity: O(1), since we are using only a constant amount of extra space for the
Space Complexity: O(1), since we are using only a constant amount of extra space for the variables ans and energy, and we are sorting the tasks in place without using any additional data structures.

*/


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
            [&](vector<int> &a, vector<int> &b) {

                return (a[1] - a[0]) >
                       (b[1] - b[0]);
            });

        long long ans = 0;
        long long energy = 0;

        for(int i=0;i<tasks.size();i++) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if(energy < minimum) { // increase initial energy if needed
                ans += (minimum - energy);
                energy = minimum;
            }
            energy -= actual;  // perform task
        }

        return (int)ans;
    }
};