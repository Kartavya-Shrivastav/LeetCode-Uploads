#include <bits/stdc++.h>
using namespace std;

/*
Problem: We have n robots, each with a position, health, and direction. Robots move simultaneously in their respective directions. When two robots collide, the one with lower health is destroyed. If both have the same health, both are destroyed. We need to return the health of the surviving robots.
Approach: We can sort the robots by their positions and use a stack to simulate the collisions. When we encounter a robot moving to the right, we push it onto the stack. When we encounter a robot moving to the left, we check for collisions with the robots on the stack.

Steps:
1. Create an order vector to sort the robots by their positions.
2. Use a stack to keep track of robots moving to the right.
3. For each robot, if it's moving to the right, push it onto the stack. If it's moving to the left, check for collisions with the robots on the stack:
   - If the top robot on the stack has more health, decrease its health and mark the current robot as dead.
   - If the current robot has more health, decrease its health and mark the top robot as dead, then pop it from the stack.
   - If both have the same health, mark both as dead and pop the top robot from the stack.
4. After processing all robots, collect the health of the surviving robots and return it.

Time Complexity: O(n log n) due to sorting the robots by their positions.
Space Complexity: O(n) for the stack and the result vector.
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n) ;
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<bool> dead(n, false);

        for (int i : order) {
            if (directions[i] == 'R') {
                st.push(i) ;
            } else {
                while (!st.empty() && directions[st.top()] == 'R') {
                    int top = st.top();
                    if (healths[top] > healths[i]) {
                        healths[top]-- ;
                        dead[i] = true;
                        break;
                    } else if (healths[top] < healths[i]) {
                        healths[i]--;
                        dead[top] = true ;
                        st.pop();
                    } else {
                        dead[i] = true;
                        dead[top] = true ;
                        st.pop();
                        break;
                    }
                }
                if (!dead[i]) st.push(i);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (!dead[i]) result.push_back(healths[i]) ;

        return result;
    }
};