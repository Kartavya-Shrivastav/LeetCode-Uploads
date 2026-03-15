class Solution {
public:
    void generate(int n, int& k, vector<char>& letters, string& temp, string& ans) {
        if (temp.size() == n) {
            k--;
            if (k == 0) ans = temp;  // found the kth one
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (!temp.empty() && temp.back() == letters[i]) continue;
            temp.push_back(letters[i]);
            generate(n, k, letters, temp, ans);
            temp.pop_back();
            if (!ans.empty()) return;  // found answer, stop early
        }
    }

    string getHappyString(int n, int k) {
        vector<char> letters = {'a', 'b', 'c'};
        string temp = "", ans = "";
        generate(n, k, letters, temp, ans);
        return ans;
    }
};