#include <bits/stdc++.h>
using namespace std;

// Problem: Design a Task Manager that supports adding, editing, removing, and executing tasks based on priority.
// Approach: Use a priority queue to manage tasks by priority and a map to track task details.

// Steps:
// 1. Use a priority queue to always get the highest priority task.
// 2. Use a map to store task details (priority and userId).
// 3. Implement methods to add, edit, remove, and execute tasks.    
// 4. Ensure that removed tasks are not executed by checking the map before execution.
// 5. When executing a task, remove it from the map to prevent re-execution.

// Time Complexity: O(log n) for add, edit, and execTop operations, O(1) for remove operation.
// Space Complexity: O(n) for storing tasks in the priority queue and map.


using int2=pair<int , int>; 
int2 mp[100001];// taskID->(prioity, userId)
class TaskManager {
    int maxI=-1;
    priority_queue<int2> pq; //(priority, taskID)
public:
    TaskManager(vector<vector<int>>& tasks) {
     //   fill(mp, mp+100001, make_pair(-1, -1));
        for(auto& t: tasks){
            int  u=t[0], i=t[1], p=t[2];
            maxI=max(maxI, i);
            mp[i]={p, u};
            pq.emplace(p, i);
        }
    }
    ~TaskManager(){
        memset(mp, -1, 8*(maxI+1));
    }
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp[i].first==p) {
                pq.pop();
                int u=mp[i].second;
                mp[i]={-1, -1}; // Remove task after execution
                return u;
            }
            pq.pop(); // Remove
        }
        return -1; // No valid tasks to execute
        
    }
};
