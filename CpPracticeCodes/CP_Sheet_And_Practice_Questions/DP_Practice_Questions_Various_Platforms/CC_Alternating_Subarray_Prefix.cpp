#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;



void work(){
    // My Solution - dp based correct same as Editorial
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // vector<int> dp(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // dp[n - 1] = 1;
    // for(int i = n - 2;i >= 0;i--){
    //     if(arr[i] > 0 && arr[i+1] < 0){
    //         dp[i] = 1 + dp[i + 1];
    //     }
    //     else if(arr[i] < 0 && arr[i + 1] > 0){
    //         dp[i] = 1 + dp[i + 1];
    //     }
    //     else{
    //         dp[i] = 1;
    //     }
    // }
    // for(int i = 0;i < n;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    // Another approach
    // An array can divided into many maximum alternating subarray
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    vector<vector<int>> parts;
    vector<int> currPart;

    currPart.push_back(arr[0]);
    for(int i = 1;i < n;i++){
        if(arr[i] * 1LL * arr[i - 1] < 0){
            currPart.push_back(arr[i]);
        }
        else{
            parts.push_back(currPart);
            currPart.clear();
            currPart.push_back(arr[i]);
            // for(int i = 0;i < currPart.size();i++){
            //     cout << currPart[i] << " ";
            // }
            // cout << endl;
        }
    }
    if(currPart.size() > 0){
        parts.push_back(currPart);
    }

    // indicaes the current index at which the answer in put
    vector<int> ans(n, 0);
    int i = 0;
    for(vector<int> currPart : parts){
        int L = currPart.size();
        while(L > 0){
            ans[i] = L;
            i++;
            // The length of maximum alternating subarray for the next index will
            // decrease by 1;
            L--;
        }
    }
    for(int i = 0;i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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


