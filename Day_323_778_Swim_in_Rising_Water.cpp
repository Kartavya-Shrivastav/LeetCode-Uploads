class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> route;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int maxElevation = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            maxElevation = max(maxElevation, elev);
            route.push_back(elev);

            if (i == n - 1 && j == n - 1)
                return maxElevation;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dir[d];
                int nj = j + dir[d + 1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({grid[ni][nj], ni, nj});
                }
            }
        }

        return maxElevation;
    }
};