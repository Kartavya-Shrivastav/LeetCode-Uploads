#include <bits/stdc++.h> 
using namespace std;

/*
Problem: We have a robot that moves on a rectangular grid of size width x height. The robot starts at the position (0, 0) facing east. The robot can receive a series of commands to move forward a certain number of steps. The robot moves in a clockwise direction around the perimeter of the grid. We need to determine the final position and direction of the robot after executing all the commands.
Approach: We can simulate the robot's movement based on the commands it receives. We will maintain the robot's current position and direction. For each command, we will update the robot's position accordingly while ensuring that it stays within the bounds of the grid. We will also keep track of the robot's direction as it moves around the perimeter.

Steps:
1. Initialize the robot's position at (0, 0) and its initial direction facing east.
2. For each command, calculate the new position based on the current direction and the number of steps to move.
3. If the robot reaches the boundary of the grid, it will turn to the next direction in a clockwise manner and continue moving until it has moved the required number of steps. 
4. After processing all commands, return the final position and direction of the robot.
5. To optimize the movement, we can calculate the perimeter of the grid and use modulo operation to determine the effective number of steps to move, as the robot will repeat its path after completing one full perimeter.

Time Complexity: O(n) where n is the number of commands, as we need to process each command once.
Space Complexity: O(1) as we are using a constant amount of space to store the robot's position and direction.

*/

class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East,1=North,2=West,3=South
    int per;

    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        if (per == 0) return;

        num %= per;

        // special case
        if (num == 0 && (x != 0 || y != 0)) return;
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            } 
            else if (dir == 1) { // North
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            } 
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            } 
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};
