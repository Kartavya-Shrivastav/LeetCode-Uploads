#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of classes with their pass and total students, and a number of extra students,
// maximize the average pass ratio after distributing the extra students.
// Approach: Use a max heap to always expand the class with the highest potential gain in pass ratio.

// Steps:
// 1. Initialize a max heap to store the potential gain in pass ratio for each class.
// 2. For each class, calculate the initial potential gain and push it onto the heap.
// 3. Distribute the extra students by always expanding the class with the highest potential gain.
// 4. After all extra students are distributed, calculate the final average pass ratio.
// 5. Return the final average pass ratio.

// Time Complexity: O(n log n) where n is the number of classes.
// Space Complexity: O(n) for the max heap.

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<tuple<double, int, int>> maxHeap;

    for (const vector<int>& c : classes) {
      const int pass = c[0];
      const int total = c[1];
      maxHeap.emplace(extraPassRatio(pass, total), pass, total);
    }

    for (int i = 0; i < extraStudents; ++i) {
      const auto [_, pass, total] = maxHeap.top();
      maxHeap.pop();
      maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
    }

    double ratioSum = 0;

    while (!maxHeap.empty()) {
      const auto [_, pass, total] = maxHeap.top();
      maxHeap.pop();
      ratioSum += pass / static_cast<double>(total);
    }

    return ratioSum / classes.size();
  }

 private:
  
  double extraPassRatio(int pass, int total) {
    return (pass + 1) / static_cast<double>(total + 1) -
           pass / static_cast<double>(total);   
    }
};