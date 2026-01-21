


class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

// OR


class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;

        int count = 0;
        for(int i=1; i<=n; i++){
            if(i == (int)sqrt(i) * (int)sqrt(i)){
                cout << i << " ";
                count++;
            }
        }

        return count;
    }
};