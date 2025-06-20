class Solution {
public:
    bool rowSearch(vector<int>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        while (high >= low) {
            int mid = (low + high) / 2;
            if (matrix[mid] == target) {
                return true;
            } else if (matrix[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows - 1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][cols - 1]) {

                if (rowSearch(matrix[mid], target))
                    return true;
                else
                    return false;

            } else if (target < matrix[mid][0]) {

                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }
        return false;
    }
};