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
    // Expensive Steps..
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    ll ans = INT_MAX;
    ans = min(min(x1, (n - x1 + 1)), min(y1, (n - y1 + 1))) + min(min(x2, (n - x2 + 1)), min(y2, (n - y2 + 1)));
    if(x1 < 1){
        x1 = 1;
    }
    if(x1 > n){
        x1 = n;
    }
    if(x2 < 1){
        x2 = 1;
    }
    if(x2 > n){
        x2 = n;
    }
    if(y1 < 1){
        y1 = 1;
    }
    if(y1 > n){
        y1 = n;
    }
    if(y2 < 1){
        y2 = 1;
    }
    if(y2 > n){
        y2 = n;
    }
    ans = min(ans, (abs(x2 - x1) + abs(y2 - y1)));
    cout << ans << endl;
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
