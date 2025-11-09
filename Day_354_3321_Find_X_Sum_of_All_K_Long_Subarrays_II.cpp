#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res;
        unordered_map<int,int> freq;

        set<pair<int,int>, cmp> topX, rest;
        long long xSum = 0;

        auto addToTop = [&](pair<int,int> p) {
            topX.insert(p);
            xSum += 1LL * p.first * p.second;
        };

        auto removeFromTop = [&](pair<int,int> p) {
            auto it = topX.find(p);
            if (it != topX.end()) {
                xSum -= 1LL * p.first * p.second;
                topX.erase(it);
            }
        };

        auto addPair = [&](pair<int,int> p) {
            if ((int)topX.size() < x) {
                addToTop(p);
                return;
            }

            if (!topX.empty()) {
                auto worst = *prev(topX.end());
                // If new pair is "better" than current worst
                if (cmp{}(p, worst)) {
                    removeFromTop(worst);
                    rest.insert(worst);
                    addToTop(p);
                } else {
                    rest.insert(p);
                }
            } else rest.insert(p);
        };

        auto erasePair = [&](pair<int,int> p) {
            if (topX.count(p)) removeFromTop(p);
            else rest.erase(p);
        };

        auto rebalance = [&]() {
            // Fill topX if it's too small
            while ((int)topX.size() < x && !rest.empty()) {
                auto best = *rest.begin();
                rest.erase(rest.begin());
                addToTop(best);
            }

            // Fix ordering if violated
            while (!topX.empty() && !rest.empty()) {
                auto worst = *prev(topX.end());
                auto best = *rest.begin();
                // If worst(topX) is still better than best(rest), stop
                if (cmp{}(worst, best)) break;

                // Swap them
                rest.erase(best);
                rest.insert(worst);
                removeFromTop(worst);
                addToTop(best);
            }
        };

        auto addElement = [&](int val) {
            int f = freq[val];
            if (f > 0) erasePair({f, val});
            freq[val]++;
            addPair({freq[val], val});
            rebalance();
        };

        auto removeElement = [&](int val) {
            int f = freq[val];
            erasePair({f, val});
            freq[val]--;
            if (freq[val] > 0) addPair({freq[val], val});
            rebalance();
        };

        // First window
        for (int i = 0; i < k; ++i) addElement(nums[i]);
        res.push_back(xSum);

        // Slide window
        for (int i = k; i < n; ++i) {
            removeElement(nums[i - k]);
            addElement(nums[i]);
            res.push_back(xSum);
        }

        return res;
    }
};