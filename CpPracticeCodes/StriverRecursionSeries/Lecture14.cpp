#include <bits/stdc++.h>
using namespace std;

// Part 1 - Using Safe1 strategy

class Solution {
    
    bool isSafe1(int row, int col, vector<string> &board, int n){
         // check upper left diagonal
        int duprow = row;
        int dupcol = col;
        
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        // check lower left diagonal
        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        col = dupcol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int &n){
        // base case.
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n;row++){
            if(isSafe1(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0;i < n;i++){
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

// Case 2 : Using Hashing Method
class Solution {
        
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,vector<int> &leftRow, vector<int> &uLD, vector<int> &lLD, int &n){
        // base case.
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n;row++){
            if(leftRow[row] == 0 && uLD[ n - 1 + row - col] == 0 && lLD[row + col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                uLD[n - 1 + row - col] = 1;
                lLD[row + col] = 1;
                solve(col + 1, board, ans,leftRow, uLD, lLD, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                uLD[n - 1 + row - col] = 0;
                lLD[row + col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        
        // for(int i = 0;i < n;i++){
        //     board[i] = s;
        // }
        vector<int> leftRow(n, 0), upperLeftDiagonal(2 * n - 1, 0), lowerLeftDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n);
        return ans;
    }
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return 0;
}