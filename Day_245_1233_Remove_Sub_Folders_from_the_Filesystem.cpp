#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a list of folder paths, remove all subfolders so that only the top-level folders remain.
// Approach: Sort the folder paths and use prefix comparison to skip nested subfolders.

// Step-by-step Procedure:
// 1. Sort the input folder paths lexicographically to ensure subfolders appear immediately after their parent.
// 2. Initialize the result vector `ans` with the first folder path.
// 3. Iterate through the sorted folder list from index 1 onwards.
// 4. For each folder, check if it starts with the last added folder in `ans` followed by a '/'.
// 5. If not, it’s not a subfolder and should be added to the result.

// Time Complexity: O(n * m * log n), where n is number of folders and m is average folder length.
// Space Complexity: O(n * m), to store the output folder list.

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};

        for (int i = 1; i < folder.size(); ++i) {
            if (folder[i].substr(0, ans.back().size() + 1) != ans.back() + "/") {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};