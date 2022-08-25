#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int


void work(){
    // E. Queen Blocks
    int a, b;
    cin >> a >> b;
    vector<vector<int>> grid(9, vector<int> (9, 0));
    grid[a][b] = 1;
    if(a > 1 && a < 8 && b > 1 && b < 8){
        grid[a - 1][b + 2] = 2;
        grid[a + 1][b + 2] = 2;
        grid[a + 2][b - 1] = 2;
    }
    else if(a == 1 && b == 1){
        grid[a + 2][b + 1] = 2;
        grid[a + 1][b + 2] = 2;
    }
    else if(a == 1 && b == 8){
        grid[a - 2][b + 1] = 2;
        grid[a - 1][b + 2] = 2;
    }
    else if(a == 8 && b == 1){
        grid[a + 1][b - 2] = 2;
        grid[a + 2][b - 1] = 2;
    }
    else if(a == 8 && b == 8){
        grid[a - 2][b - 1] = 2;
        grid[a - 1][b - 2] = 2;
    }
    else {
        if(a == 1){
            grid[a + 2][b + 1] = 2;
            grid[a - 1][b + 2] = 2;

        }
        else if(a == 8){
            grid[a - 1][b + 2] = 2;
            grid[a - 1][b - 2] = 2;
        }
        else if(b == 1){
            grid[a - 2][b + 1] = 2;
            grid[a + 2][b + 1] = 2;
        }
        else if(b == 8){
            grid[a - 2][b - 1] = 2;
            grid[a + 2][b - 1] = 2;
        }
    }
    for(int i = 1;i < 9;i++){
        for(int j = 1;j < 9;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}