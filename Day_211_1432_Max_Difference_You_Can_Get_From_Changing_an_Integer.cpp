class Solution {
public:
    int maxDiff(int num) {
        // Convert the integer to a string for easy manipulation
        const string s = to_string(num);

        // Find the first digit that is not '9' (for maximizing the number)
        int firstNot9 = s.find_first_not_of('9');

        // Find the first digit that is not '0' or '1' (for minimizing the number)
        int firstNot01 = s.find_first_not_of("01");

        // If all digits are '9', set index to 0 (no change needed)
        if (firstNot9 == string::npos)
            firstNot9 = 0;

        // If all digits are '0' or '1', set index to 0 (no change needed)
        if (firstNot01 == string::npos)
            firstNot01 = 0;

        // Create copies of the original string for manipulation
        string a = s;
        string b = s;

        // Replace all occurrences of the first non-'9' digit with '9' to maximize
        replace(a.begin(), a.end(), s[firstNot9], '9');

        // Replace all occurrences of the first non-'0'/'1' digit with '1' (if first digit) or '0' (otherwise) to minimize
        replace(b.begin(), b.end(), s[firstNot01], firstNot01 == 0 ? '1' : '0');

        // Return the difference between the maximized and minimized numbers
        return stoi(a) - stoi(b);
    }
};