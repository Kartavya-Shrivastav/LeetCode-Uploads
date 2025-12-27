#include<bits/stdc++.h>
using namespace std;

// Problem: Meeting Rooms III
// Approach: Use two priority queues, one for available rooms and another for occupied rooms. Sort meetings by start time and assign rooms based on availability and meeting end times.

// Steps:
// 1. Sort the meetings based on their start times.
// 2. Use a min-heap (priority queue) to keep track of available rooms.
// 3. Use another min-heap to keep track of occupied rooms and their end times.
// 4. For each meeting, check if any rooms have become available by comparing the current meeting's start time with the end times in the occupied rooms heap.
// 5. If a room is available, assign it to the meeting and update the end time.
// 6. If no rooms are available, wait for the earliest room to free up and assign it to the meeting.

// Time Complexity: O(m log m + m log n) where m is the number of meetings and n is the number of rooms.
// Space Complexity: O(n + m) for the priority queues and count array.


class Solution {
public:
    int mostBooked(int n1, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        long long n = meetings.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,         greater<pair<long long,long long>>> pq;
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