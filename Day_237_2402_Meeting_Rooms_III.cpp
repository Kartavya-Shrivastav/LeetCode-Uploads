#include <bits/stdc++.h>
using namespace std;

// Problem: Given n meeting rooms and a list of meetings with their start and end times, find the room that is most booked.
// Approach: Use a priority queue to manage the rooms and their availability, and count the number of meetings in each room.

// Steps:
// 1. Sort the meetings based on their start times.
// 2. Use a priority queue to keep track of the end times of meetings in each room.
// 3. Use another priority queue to manage the available rooms.
// 4. For each meeting, check if there is an available room or if a room can be reused.
// 5. Count the number of meetings in each room and return the room with the maximum count.
// 6. Return the index of the room that has the most meetings booked.

// Time Complexity: O(n log n) where n is the number of meetings.
// Space Complexity: O(n) for storing the count of meetings in each room.

class Solution {
public:
    int mostBooked(int n1, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        long long n = meetings.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        priority_queue<long long,vector<long long>,greater<long long>> pq1;
        for(long long i=0;i<n1;i++) pq1.push(i);
        vector<long long> cnt(n,0);
        for(long long i=0;i<n;i++){
            while(!pq.empty() && pq.top().first <= meetings[i][0]){
                pair<long long,long long> x = pq.top();
                pq.pop();
                pq1.push(x.second);
            }
            if(!pq1.empty()){
                long long a = pq1.top();
                pq1.pop();
                cnt[a]++;
                pq.push({meetings[i][1],a});
            }else{
                pair<long long,long long> b = pq.top();
                pq.pop();
                long long start = b.first;
                long long room = b.second;

                cnt[room]++;
                pq.push({start+meetings[i][1] - meetings[i][0],room});
            }
        }
        
        int k = max_element(cnt.begin(),cnt.end())-cnt.begin();
       return k;
    }
};