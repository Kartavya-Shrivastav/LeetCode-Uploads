class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        // Remove leading 'L'
        int left = 0;
        while (left < n && directions[left] == 'L')
            left++;

        // Remove trailing 'R'
        int right = n - 1;
        while (right >= 0 && directions[right] == 'R')
            right--;

        // Count remaining 'L' and 'R'
        int collisions = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] == 'L' || directions[i] == 'R')
                collisions++;
        }

        return collisions;
    }
};
