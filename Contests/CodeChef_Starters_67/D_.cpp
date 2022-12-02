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

bool comp(pair<ll, ll> a1, pair<ll, ll> a2){
    return (a1.first * a2.second) > (a1.second * a2.first);
}

void work()
{
    // My Try :
    // Musical Rods.
    // ll n;
    // cin >> n;
    // vector<ll> lengths(n, 0);
    // for(auto &x : lengths) cin >> x;
    // vector<ll> beauty(n, 0);
    // for(auto &x : beauty) cin >> x;
    // // Recursion.
    // // We have to recursion perfectly.
    // // curr_pos, 
    // ll ans = solve(0, )

    // Greedy.
    // ll sum  = 0;
    // for(int i = 0;i < n;i++){
    //     sum += lengths[i];
    // }
    // ll ans = 0;
    // ll full = n;
    // while(full != 0){
    //     ll maxi = 0;
    //     int index = 0;
    //     for(int i = 0;i < n;i++){
    //         ll curr = (beauty[i] * (sum - lengths[i]));
    //         if(curr > maxi){
    //             maxi = curr;
    //             index = i;
    //         }
    //     }
    //     cout << "Inside loop : " << index << " lengths : " << lengths[index] << endl;
    //     cout << "ans before : " << ans << endl;
    //     ans += maxi;
    //     cout << "ans after : " << ans << endl;
    //     sum -= lengths[index];
    //     cout << "sum is : " << sum << endl;
    //     // lengths[index] = 0;
    //     beauty[index] = 0;
    //     full--;
    // }
    // cout << ans << endl;


    // Editorial - Musical Rods.
    // Sorting and Exchange Arguments.
    ll n;
    cin >> n;
    vector<ll> lengths(n, 0);
    for(auto &x : lengths) cin >> x;
    vector<ll> beauty(n, 0);
    for(auto &x : beauty) cin >> x;
    // Sort them by descending order of lengths/beauty.
    vector<pair<ll, ll>> rods(n, {0, 0});
    for(int i = 0;i < n;i++){
        rods[i].first = lengths[i];
        rods[i].second = beauty[i];
    }
    sort(rods.begin(), rods.end(), comp);
    ll ans = 0, curr = 0;
    for(int i = 0;i < n;i++){
        ans += (rods[i].second * curr);
        curr += (rods[i].first);
    }
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