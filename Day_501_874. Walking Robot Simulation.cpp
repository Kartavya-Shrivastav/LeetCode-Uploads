#include <bits/stdc++.h>
using namespace std;

/*
Problem: We have a robot that starts at the origin (0, 0) facing north. The robot can receive a series of commands to move forward, turn left, or turn right. There are also obstacles on the grid that the robot cannot pass through. We need to determine the maximum distance from the origin that the robot can reach after executing all the commands.
Approach: We can simulate the robot's movement based on the commands it receives. We will maintain the robot's current position and direction. For each command, we will update the robot's position accordingly while checking for obstacles. We will also keep track of the maximum distance from the origin that the robot reaches during its movement.

Steps:
1. Store the obstacles in a set for O(1) lookup.
2. Define the possible directions (North, East, South, West) and their corresponding coordinate changes.
3. Initialize the robot's position at (0, 0) and its initial direction facing north.
4. Iterate through each command:
   - If the command is -1, turn right (update direction).
   - If the command is -2, turn left (update direction).
   - If the command is a positive integer, move forward step by step:
     - For each step, calculate the next position based on the current direction.
     - Check if the next position is an obstacle. If it is, stop moving in that direction.
     - If it's not an obstacle, update the robot's position and calculate the distance from the origin. Update the maximum distance if necessary.   

Time Complexity: O(n + m) where n is the number of commands and m is the number of obstacles, due to the need to process each command and store obstacles in a set.
Space Complexity: O(m) for storing the obstacles in a set.
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles for quick lookup
        set<pair<int,int>> blocked;
        for (auto &o : obstacles) {
            blocked.insert({o[0], o[1]});
        }

        // Directions: North, East, South, West
        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int x = 0, y = 0;
        int dir = 0; // start facing North
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                // turn right
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                // turn left
                dir = (dir + 3) % 4;
            } 
            else {
                // move forward step by step
                while (cmd--) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;

                    // stop if obstacle is ahead
                    if (blocked.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};  