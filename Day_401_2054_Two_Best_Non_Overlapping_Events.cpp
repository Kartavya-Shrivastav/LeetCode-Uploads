#include <bits/stdc++.h>
using namespace std;

// Problem: Two Best Non-Overlapping Events
// Approach: Sweep Line Algorithm with Event Sorting

// Steps:
// 1. Create a list of time points for all events, marking start and end times.
// 2. Sort these time points. When times are equal, process end times before start times.
// 3. Use a variable to keep track of the maximum value of events that have ended so far.
// 4. As we process each start time, calculate the potential maximum value by adding the current event's value to the maximum value of previously ended events.
// 5. Update the answer accordingly and return it at the end.

// Complexity:
// Time: O(n log n) due to sorting the events
// Space: O(n) for storing the time points.

class Solution {
public:
    using info=tuple<int, bool, int>;
    static int maxTwoEvents(vector<vector<int>>& events) {
        const int n=events.size();
        vector<info> time(n*2);
        for(int i=0; i<n; i++){
            int s=events[i][0], e=events[i][1], v=events[i][2];
            time[2*i]={s, 0, v};
            time[2*i+1]={e, 1, v};
        }
        sort(time.begin(), time.end());
        int ans=0, maxV=0, n2=n*2;
        for(auto& [t, isEnd, v]: time){
            if (isEnd) maxV=max(maxV, v);
            else ans=max(ans, maxV+v);
        }
        return ans;    
    }
};
