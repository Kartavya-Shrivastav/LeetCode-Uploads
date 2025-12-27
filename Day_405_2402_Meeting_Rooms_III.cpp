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