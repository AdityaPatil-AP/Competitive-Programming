#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

// const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    // for(auto x : arr) cout << x << " ";
    // cout << endl;
    bool isZeroPresent = false;
    int countNegative = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] < 0){
            countNegative++;
        }
        if(arr[i] == 0){
            isZeroPresent = true;
        }
    }
    if(isZeroPresent || countNegative % 2 == 0 || countNegative == 0){
        cout << 0 << endl;
    }
    else cout << 1 << endl;
}

int main(){
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


