#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int f(int ind1, int ind2, string &a, string &b, vector<vector<int>> &dp){
    // Base Case
    if(ind1 == 0 || ind2 == 0){
        return 0;
    }

    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }

    // Explorations
    if(a[ind1 - 1] == b[ind2 - 1]){
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, a, b, dp);
    }
    else{
        int p1 = 0 + f(ind1 - 1, ind2, a, b, dp);
        int p2 = 0 + f(ind1, ind2 - 1, a, b, dp);
        return dp[ind1][ind2] = max(p1, p2);
    }

}

void work(){
    // Recursion and Tabulation
    // string m, w;
    // cin >> m >> w;
    // int a = m.size();
    // int b = w.size();
    // int lcs = 0;
    // if(a >= b){
    //     vector<vector<int>> dp(b + 1, vector<int>(a + 1, -1));
    //     lcs = f(b, a, w, m, dp);
    //     if(lcs == b){
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // else{
    //     vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    //     lcs = f(a, b, m, w, dp); 
    //     if(lcs == a){
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // cout << "NO" << endl;

    // Memoisation
    // string m, w;
    // cin >> m >> w;
    // int a = m.size();
    // int b = w.size();
    // if(a > b){
    //     string s;
    //     s = m;
    //     m = w;
    //     w = s;
    // }
    // a = m.size();
    // b = w.size();
    // vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    // for(int i = 0;i <= a;i++) dp[i][0] = 0;
    // for(int i = 0;i <= b;i++) dp[0][i] = 0;

    // for(int i = 1;i <= a;i++){
    //     for(int j = 1;j <= b;j++){
    //         if(m[i - 1] == w[j - 1]){
    //             dp[i][j] = 1 + dp[i - 1][j - 1];
    //         }
    //         else{
    //             int p1 = 0 + dp[i - 1][j];
    //             int p2 = 0 + dp[i][j - 1];
    //             dp[i][j] = max(p1, p2);
    //         }
    //     }
    // }
    // int lcs = dp[a][b];
    // if(lcs == a){
    //     cout << "YES" << endl;
    // }
    // else{ 
    //     cout << "NO" << endl;
    // }

    // Time limit exceeded because of constraints
    // Using greedy appraoch this can be done in O(a + b)
    // we will keep m as subsequence of w;
    string m, w;
    cin >> m >> w;
    if(m.size() >= w.size()){
        string temp;
        temp = m;
        m = w;
        w = temp;
    }
    int j = 0;
    bool flag = true;
    for(int i = 0;i < m.length();){
        while(j < w.length()){
            if(m[i] == w[j])
                break;
            j++;
        }
        if(j >= w.length()){
            flag = false;
            break;
        }
        i++;
        j++;
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


