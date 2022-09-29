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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    unordered_map<int, int> mp;
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;
    }
    int maxFreq = INT_MIN;
    for(auto it : mp){
        if(it.second > maxFreq){
            maxFreq = it.second;
        }
    }
    cout << n - maxFreq << endl;
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


