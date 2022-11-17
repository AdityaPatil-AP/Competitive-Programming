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
    // Candies
    ll n;
    cin >> n;
    vector<ll> arr(2* n, 0);
    for(auto &x : arr) cin >> x;

    unordered_map<int, int> mp;
    for(int i = 0;i < 2 * n;i++){
        mp[arr[i]]++;
    }
    bool ans = true;
    for(auto it : mp){
        if(it.second > 2){
            ans = false;
            break;
        }
    }
    (ans) ? cout << "YES" : cout << "NO";
    cout << endl;
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
