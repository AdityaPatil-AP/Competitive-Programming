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

void work()
{
    // My Try :
    // Range Assign, Number of Distinct Elements Minimize
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    if(arr.size() <= 2){
        cout << "YES" << endl;
        return;
    }
    ll first = arr[0];
    ll last = arr[n - 1];
    set<int> s1;
    set<int> s2;
    for(int i = 1;i < n;i++){
        if(arr[i] == first){
            s1.insert(i);
        }
    }
    for(int i = 0;i < n - 1;i++){
        if(arr[i] == last){
            s2.insert(i);
        }
    }
    bool ans = false;
    for(auto i : s1){
        if(s2.find(i + 1) != s2.end()){
            ans = true;
        }
    }
    if(s1.count(n - 1) || s1.count(n - 2) || s2.count(0) || s2.count(1) ||  ans){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        work();
    }
    return 0;
}
