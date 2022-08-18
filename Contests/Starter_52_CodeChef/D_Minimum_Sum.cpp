#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;



void work(){
   // Minimum Sum
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // sort(arr.begin(), arr.end());
    // int curr = 0;
    // while(curr < n){
    //     int temp = curr;
    //     int j = curr + 1;
    //     while(j < n){
    //         if(arr[j]%arr[temp] == 0){
    //             arr[j] = arr[temp];
    //             curr++;
    //         }
    //         j++;
    //     }
    //     if(curr - temp > 0){
    //         sort(arr.begin(), arr.end());
    //     }
    //     curr++;
    // }
    // int ans = 0;
    // for(int i = 0;i < n;i++){
    //     ans += arr[i];
    // }
    // cout << ans << endl;

    // Editor Solution
    int n;
    cin >> n;
    vector<long long int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    long long int res = arr[0];
    for(int i = 1;i < n;i++){
        res = __gcd(res, arr[i]);
    }
    cout << (long long int)n * res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
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


