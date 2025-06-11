class Solution {
public:
    int lengthOfLastWord(string s) {
        
        reverse(s.begin(), s.end());
        int start_idx = 0;
        int count = 0;
        int n = s.size();
        while(start_idx < n && s[start_idx]== ' ')
        {
            start_idx++;
        }
        while(start_idx < n && s[start_idx]!= ' ')
        {
            count++;
            start_idx++;
        }
        return count;
    }
};