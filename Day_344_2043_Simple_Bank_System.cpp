#include <bits/stdc++.h>
using namespace std;

// Problem: 2043. Simple Bank System
// Approach: Implement a Bank class with methods for transferring, depositing, and withdrawing money.

// Steps:   
// 1. Create a Bank class that stores account balances in a vector.
// 2. Implement a constructor that initializes the balances.
// 3. Implement the transfer method to move money between accounts if valid.
// 4. Implement the deposit method to add money to an account if valid.
// 5. Implement the withdraw method to remove money from an account if valid.

// Time Complexity: O(1) for each operation
// Space Complexity: O(n) for storing account balances

class Bank {
private:
    vector<long long> bal;
    int n;

    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool transfer(int from, int to, long long amt) {
        if (!valid(from) || !valid(to) || bal[from - 1] < amt) return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    bool deposit(int acc, long long amt) {
        if (!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    bool withdraw(int acc, long long amt) {
        if (!valid(acc) || bal[acc - 1] < amt) return false;
        bal[acc - 1] -= amt;
        return true;
    }
};