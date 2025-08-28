#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Problem: Sort a matrix by its diagonals
// Approach: Use heaps to sort the elements along each diagonal

// Steps:
// 1. Create two hash maps to store max heaps and min heaps for each diagonal.
// 2. Iterate through the matrix and populate the heaps based on the diagonal key (i - j).
// 3. Reconstruct the matrix by popping elements from the heaps in sorted order.
// 4. Return the sorted matrix.

// Time Complexity: O(N log N) where N is the number of elements in the matrix.
// Space Complexity: O(N) for the hash maps.

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, priority_queue<int>> maxHeaps;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) minHeaps[key].push(grid[i][j]);
                else maxHeaps[key].push(grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) {
                    grid[i][j] = minHeaps[key].top();
                    minHeaps[key].pop();
                } else {
                    grid[i][j] = maxHeaps[key].top();
                    maxHeaps[key].pop();
                }
            }
        }
        return grid;
    }
};