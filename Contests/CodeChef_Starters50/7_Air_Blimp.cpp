#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

void work(){
    // MY wrong answer
    // int n, x, y;
    // cin >> n >> x >> y;
    // int div = max(x, y);
    // int *arr = new int[n];
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // int max = *max_element(arr, arr + n);
    // // cout << max << endl;
    // if(max % div == 0){
    //     cout << max/div << endl;
    // }
    // else{
    //     cout << max/div + 1 << endl;
    // }

    // Editor's Solution
    int n, x, y;
    cin >> n >>  x >> y;
    vector<int> vec(n, 0);
    for(int i = 0;i < n;i++){
        cin >> vec[i];
    }
    if(x <= y){
        int max = *max_element(vec.begin(), vec.end());
        max = (0LL, max);
        cout << ceil((max + y - 1)/y) << endl;
        return;
    }
    int total_blimps = 0;
    for(int i = n - 1;i >= 0;i--){
        vec[i] = max(0ll, vec[i] - (total_blimps * y));
        total_blimps = total_blimps + (vec[i] + x - 1)/x;
    }
    cout << total_blimps << endl;
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