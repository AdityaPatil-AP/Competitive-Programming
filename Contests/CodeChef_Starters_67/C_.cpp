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
    // Maximum Angriness.
    ll n, k;
    cin >> n >> k;
    ll ans;
    if(k >= n/2){
        ans = (n * (n - 1))/2;
        cout << ans << endl;
    }
    else{
        ans = ((n * (n - 1))/2 - ((n - k - 1) * (n - k))/2);
        // cout << "Check ans : " << ans << endl;
        ans += (k * (n - (2 * k)));
        ans += ((k - 1) * k)/2;
        cout << ans << endl;
    }
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
