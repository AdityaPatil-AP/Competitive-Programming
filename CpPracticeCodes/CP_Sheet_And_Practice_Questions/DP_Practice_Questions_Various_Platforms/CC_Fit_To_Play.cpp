#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Approach 1
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // vector<int> maxarr(n, 0), minarr(n, 0);
    // // Making the maxarray
    // maxarr[n - 1] = arr[n - 1];
    // for(int i = n - 2;i >= 0;i--){
    //     maxarr[i] = max(arr[i], maxarr[i + 1]);
    // }
    // // Making the minarray
    // minarr[0] = arr[0];
    // for(int i = 1;i < n;i++){
    //     minarr[i] = min(arr[i], minarr[i - 1]);
    // }
    // // Finding the max of maxarr[i] - minarr[i]
    // int ans = 0;
    // for(int i = 0;i < n;i++){
    //     ans = max(ans, maxarr[i] - minarr[i]);
    // }
    // // cout << ( (ans==0)?(ans) : "UNFIT") << endl;
    // if(ans > 0){
    //     cout << ans << endl;
    // }
    // else {
    //     cout << "UNFIT" << endl;
    // }

    // Approach 2
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int minm = arr[0];
    int ans = 0;
    for(int i = 1;i < n;i++){
        ans = max(arr[i] - minm, ans);
        minm = min(arr[i], minm);
    }
    if(ans > 0){
        cout << ans << endl;
    }
    else{
        cout << "UNFIT" << endl;
    }
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


