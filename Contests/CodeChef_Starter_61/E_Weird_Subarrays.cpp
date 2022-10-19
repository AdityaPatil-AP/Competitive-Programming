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

const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    // E) Weird Subarrays
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    bool increasing = false, decreasing = false;
    long long int ans = 1;
    int prev = 0;
    int change = 0;
    for(int i = 1;i < n;i++){
        // 1) Decreasing -> Increasing.
        // 2) Increasing -> Decreasing.
        // 3) Increasing or Decreasing.
        if(arr[i] < arr[i - 1]){
            decreasing = true;
            if(increasing == true){
                prev = i - 1;
                ans += (i - prev + 1);
                increasing = false;
                decreasing = true;
                change++;
            }
            else{
                ans += (i - prev + 1);
            }
        }
        else if(arr[i] > arr[i - 1]){
            increasing = true;
            if(decreasing == true){
                // prev = i - 1;
                // ans += (i - prev + 1);
                decreasing = false;
            }
            ans += (i - prev + 1);
        }
    }
    // cout << change << endl;
    // // if(change >= 1) change--;
    cout << (ans) << endl;
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


