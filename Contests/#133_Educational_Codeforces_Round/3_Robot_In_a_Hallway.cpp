#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int

int totalTime(vector<vector<pair<int, bool>>> &vec, int i, int j, int count){
    int tt = INT_MAX;
    if(count == 2 * vec[1].size()){
        return tt;
    }
    vec[i][j].second = true;
    // up
    if((i - 1 >= 0) && (vec[i - 1][j]).first - tt <= 0 && (vec[i - 1][j]).second == false){
        tt = min(tt, 1 + totalTime(vec, i - 1, j, count + 1));
    }
    // down
    if((i + 1 <= 1) && (vec[i + 1][j]).first - tt <= 0 && (vec[i + 1][j]).second == false){
        tt = min(tt, 1 + totalTime(vec, i + 1, j, count + 1));
    }
    // left
    if((j - 1 >= 0) && (vec[i][j - 1]).first - tt <= 0 && (vec[i][j - 1]).second == false){
        tt = min(tt, 1 + totalTime(vec, i, j - 1, count + 1));
    }
    // right
    int m = vec[1].size();
    if((j + 1 < m) && (vec[i][j + 1]).first - tt <= 0 && (vec[i][j + 1]).second == false){
        tt = min(tt, 1 + totalTime(vec, i, j + 1, count + 1));
    }
    // remain at the same place
    tt = min(tt, 1 + totalTime(vec, i, j, count));
    vec[i][j].second = false;

    return tt;
}

void work(){
    int m;
    cin >> m;
    vector<vector<pair<int, bool>>> vec(2, vector<pair<int,bool>> (m, {0, false}));
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < m;j++){
            cin >> vec[i][j].first;
        }
    } 
    // vector<vector<int>> dp(2, vector<int> (m, 0));
    int time = totalTime(vec, 0, 0, 1);
    return;
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