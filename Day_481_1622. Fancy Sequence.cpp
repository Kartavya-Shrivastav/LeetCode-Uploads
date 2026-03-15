#include <bits/stdc++.h>
using namespace std;

/*
Problem: Implement a class Fancy that supports the following operations:
1. append(val): Append an integer val to the end of the sequence.
2. addAll(inc): Add an integer inc to all existing values in the sequence.
3. multAll(m): Multiply all existing values in the sequence by an integer m.
4. getIndex(idx): Get the current value at index idx (0-indexed) of the sequence modulo 10^9 + 7. If the index is out of bounds, return -1.

The sequence starts empty, and the operations are applied in the order they are called.

Approach: We can maintain two variables a and b to represent the transformations applied to the sequence due to the addAll and multAll operations.
When we append a new value, we can store it in a way that allows us to retrieve the original value before transformations. When we call getIndex,
we can apply the transformations to the stored value to get the current value at that index. 

Steps:
1. Initialize a and b to represent the transformations (initially a = 1, b = 0).
2. For append(val), store the value in a way that allows us to retrieve the original value (e.g., store (val - b) / a). 
3. For addAll(inc), update b to represent the addition transformation (b = b + inc).
4. For multAll(m), update a and b to represent the multiplication transformation (a = a * m, b = b * m).
5. For getIndex(idx), check if idx is within bounds. If it is, retrieve the original value and apply the transformations to get the current value (current_value = a * stored_value + b).   

Time Complexity: O(1) for each operation, since we are using constant time operations to update and retrieve values.    
Space Complexity: O(n) for storing the values in the sequence, where n is the number of append operations.

*/

class Fancy {
private:
    const int mod = 1e9 + 7;
    vector<long long> val;
    long long a, b;
    long long modPow(long long x, long long y, long long mod) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            y = y / 2;
            x = (x * x) % mod;
        }
        return res;
    }
public:
    Fancy() : a(1), b(0) {
    }
    
    void append(int val) {
        long long x = (val - b + mod) % mod;
        this->val.push_back((x * modPow(a, mod - 2, mod)) % mod);
    }
    
    void addAll(int inc) {
        b = (b + inc) % mod;
    }
    
    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= val.size()) 
            return -1;
        return (a * val[idx] + b) % mod;
    }
};