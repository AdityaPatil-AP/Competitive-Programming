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
    // My Try : Correct

    // ll n, c;
    // cin >> n >> c;

    // vector<pair<ll, ll>> arr;
    // for(int i = 0;i < n;i++){
    //     ll x;
    //     cin >> x;
    //     arr.push_back({x + min((ll)i + 1, n - i), x + i + 1});
    // }

    // sort(arr.begin(), arr.end());

    // vector<ll> prefSum;
    // prefSum.push_back(0);
    // for(int i = 0;i < n;i++){
    //     prefSum.push_back(prefSum.back() + arr[i].first);
    // }

    // ll ans = 0;
    // for(int i = 0;i < n;i++){
    //     ll new_c = c - arr[i].second;
    //     int l = 0, r = n;
    //     ll mx = 0;
    //     while(l <= r){
    //         ll mid = (l + r) >> 1;
    //         // calculate price.
    //         ll price = prefSum[mid];
    //         ll now = mid + 1;
    //         // nahi samjhi.
    //         if(mid > i){
    //             price -= arr[i].first;
    //             now--;
    //         }
    //         if(price <= new_c){
    //             mx = max(now, mx);
    //             l = mid + 1;
    //         }
    //         else  r = mid - 1;
    //     }
    //     ans = max(ans, (ll)mx);
    // }
    // cout << ans << endl;

    // Repeat.
    ll n, c;
    cin >> n >> c;

    // The first teleporter we have to take from point 0.
    // We have to check for every index what is the maximum 
    // number of teleporters we can use. and return the maximum 
    // among them.

    vector<pair<ll, ll>> arr(n + 1);

    for(int i = 1;i <= n;i++){
        ll x;
        cin >> x;
        arr[i].first = min(i + x, n + 1 - i + x);
        arr[i].second = i + x;
    }

    sort(arr.begin(), arr.end());

    // We can use prefix sums for finding the number of teleporters 
    // we can use with c amount of coins.

    vector<ll> prefSum(n + 1, 0);
    for(int i = 1;i <= n;i++){
        prefSum[i] += prefSum[i - 1] + arr[i].first;
    }

    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ll new_c = c - arr[i].second;

        // Video wale bande ne kiya.
        // ll j = upper_bound(prefSum.begin(), prefSum.end(), new_c) - prefSum.begin();
        // j--;
        // if(j < i){
        //     ans = max(ans, j + 1);
        // }   
        // else{
        //     ll rem = c - (prefSum[i - 1] + arr[i].second);
        //     if(rem < 0){
        //         ans = max(ans, (ll)i - 1);
        //         continue;
        //     }
        //     ll j = upper_bound(prefSum.begin() + i + 1, prefSum.end(), prefSum[i] + rem) - prefSum.begin();
        //     j--;
        //     ans = max(ans, i + (j - i));
        // }

        // Tutorial mai diya hai.
        ll l = 0, r = n;
        ll mx = 0;
        while(l <= r){
            ll mid = (l + r) >> 1;
            ll now = mid + 1;
            ll price = prefSum[mid];
            if(mid + 1 > i){
                price -= arr[i].first;
                now--;
            }
            if(price <= new_c){
                mx = max(mx, now);
                l = mid + 1;
            }
            else r = mid - 1;

        }
        ans = max(ans, mx);
    }
    cout << ans << endl;
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


