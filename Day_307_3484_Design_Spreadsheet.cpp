#include<bits/stdc++.h> 
using namespace std;

// Problem: Design a Spreadsheet that supports setting cell values, resetting cells, and evaluating formulas.
// Approach: Use a 2D vector to represent the spreadsheet and implement methods to manipulate cells.

// Steps:
// 1. Use a 2D vector to store cell values, initialized to zero.
// 2. Implement setCell to update the value of a specific cell.
// 3. Implement resetCell to reset a specific cell to zero.
// 4. Implement getValue to evaluate a formula that can include cell references and integers.
// 5. Parse the formula to identify cell references and integers, then compute the result.
// 6. Return the computed value from getValue.

// Time Complexity: O(1) for setCell and resetCell, O(k) for getValue where k is the number of terms in the formula.
// Space Complexity: O(m*n) for storing the spreadsheet where m is the number of rows and n is the number of columns.

class Spreadsheet {
private:
    vector<vector<int>>sheet;
    pair<int,int> getIndices(string &cell){
        int n = cell.size();
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1,n-1));
        return {row,col};
    }
public:
    Spreadsheet(int rows) {
       
        sheet.assign(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        auto [row,col] = getIndices(cell);
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row,col] = getIndices(cell);
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        int splitIdx = formula.find('+');
        string x = formula.substr(1,splitIdx-1);
        string y = formula.substr(1+splitIdx,n-splitIdx-1);
        int num1 = 0,num2 = 0;
        if(isalpha(x[0])){
            auto [row1,col1] = getIndices(x);
            num1 = sheet[row1][col1];
        }else{
            num1 = stoi(x);
        }
        if(isalpha(y[0])){
            auto [row2,col2] = getIndices(y);
            num2 = sheet[row2][col2];
        }else{
            num2 = stoi(y);
        }

        return num1+num2;
    }
};
