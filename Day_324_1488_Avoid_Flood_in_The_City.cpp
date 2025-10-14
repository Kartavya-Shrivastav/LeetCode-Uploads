#include <bits/stdc++.h>
using namespace std;

// Problem: 1488. Avoid Flood in The City
// Approach: Union-Find to manage dry days and rainy days

// Steps:
// 1. Create a Union-Find data structure to manage the days and find the next dry day.
// 2. Use a hash map to track the last rainy day for each lake.
// 3. Iterate through the rains array, marking rainy days and finding dry days as needed.
// 4. If a lake is about to be flooded again, find the next available dry day and assign it to dry that lake.
// 5. If no dry day is available before the next rain, return an empty array.
// 6. Return the array indicating which lakes are dried on dry days and -1 on rainy days.

// Time Complexity: O(n log n) in the worst case due to Union-Find operations.
// Space Complexity: O(n) for the Union-Find structure and the hash map.

class UnionFind{
public:
    vector<int> root;
    UnionFind(vector<int>& rains, int n){
        root.resize(n+1);
        root[n]=n;
        for(int i=n-1; i>=0; i--)
            root[i]=(rains[i])?root[i+1]:i;
    }
    int Find(int x){
        return (x==root[x])?x:root[x]=Find(root[x]);
    }
    void UnionNext(int x){
        root[x]=Find(x+1);// union x & x+1
    }
};
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n=rains.size();

        // root is the 1st day dry after a succesive rainy days
        UnionFind G(rains, n); 
        unordered_map<int, int> rainDay;//lake->last rainy day
        rainDay.reserve(n);
        vector<int> ans(n, 1);// dry lake 1 by default
        for(int i=0; i<n; i++){
            const int lake=rains[i];
            if (lake>0){
                ans[i]=-1;
                auto it=rainDay.find(lake);
                if (it!=rainDay.end()){
                    int prev=it->second;
                    int dry=G.Find(prev+1); //find next dry day after prev
                    if (dry>=i) return {};  //no dry day before i
                    ans[dry]=lake;      // dry that lake
                    G.UnionNext(dry);   // dry day as used
                    it->second=i;       // update last rain
                }
                else rainDay[lake]=i;
            } 
        }
        return ans;
    }
};