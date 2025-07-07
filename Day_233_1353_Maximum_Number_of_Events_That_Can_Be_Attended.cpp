#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of events where each event is represented by a start and end day, find the maximum number of events that can be attended.
// Approach: Use a greedy algorithm with a priority queue to keep track of the end days of events that can be attended.

// Steps:
// 1. Sort the events by their start day.
// 2. Use a priority queue to manage the end days of events that can be attended.
// 3. Iterate through the events, adding events to the priority queue if they start on or after the current day.
// 4. Pop the earliest ending event from the priority queue for each day, and increment the count of attended events.
// 5. Continue until all events are processed or no more events can be attended.

// Time Complexity - O(n log n) for sorting the events, O(n log n) for managing the priority queue, where n is the number of events.
// Space Complexity - O(n) for the priority queue to store the end days of events.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, index = 0, n = events.size(), result = 0;
        
        while (!minHeap.empty() || index < n) {
            if (minHeap.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;
            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return result;
    }
};