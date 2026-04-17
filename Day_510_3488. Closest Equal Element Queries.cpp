#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a circular array of integers nums and an array of queries, return an array of integers where the i-th element is the shortest distance from index queries[i] to the closest equal element in nums. If there is no such element, return -1 for that query.
Approach: We can use a hash map to store the positions of each unique element in the nums array. For each query, we can check the positions of the corresponding element and calculate the distance to the closest occurrence. Since the array is circular, we need to consider both directions (clockwise and counterclockwise) when calculating the distance.

Steps:
1. Create a hash map to store the positions of each unique element in the nums array.   
2. Iterate through the nums array and populate the hash map with the indices of each element.
3. Create an answer array initialized with -1 to store the shortest distances for each index.
4. For each unique element in the hash map, calculate the shortest distance to the closest equal element for each of its positions.
5. For each query, retrieve the precomputed shortest distance from the answer array and return it.

Time Complexity: O(n + m), where n is the size of the nums array and m is the number of queries. We iterate through the nums array once to populate the hash map and then iterate through the unique elements to compute the distances. Finally, we retrieve the results for each query.
Space Complexity: O(n), as we are using a hash map to store the positions of each unique element and an answer array to store the shortest distances for each index.
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        vector<int> answer(n, -1);

        for (auto& entry : positions) {
            vector<int>& pos = entry.second;
            int m = pos.size();

            if (m == 1) continue;

            for (int i = 0; i < m; i++) {
                int curr = pos[i];

                int prev = pos[(i - 1 + m) % m];
                int next = pos[(i + 1) % m];

                int distPrev = abs(curr - prev);
                distPrev = min(distPrev, n - distPrev);

                int distNext = abs(curr - next);
                distNext = min(distNext, n - distNext);

                answer[curr] = min(distPrev, distNext);
            }
        }

        vector<int> result;
        for (int idx : queries) {
            result.push_back(answer[idx]);
        }

        return result;
    }
};