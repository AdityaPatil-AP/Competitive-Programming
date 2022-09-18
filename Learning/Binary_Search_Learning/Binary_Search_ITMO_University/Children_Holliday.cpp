#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int N = 1000000;
#define pb push_back

ll m, n;
vector<ll> ti;
vector<ll> zi;
vector<ll> yi;
vector<ll> countB;
bool good(ll t){
    ll ballons = 0;
    for(int i = 0;i < n;i++){
        ll count = 0;
        for(ll j= ti[i];j <= t;j += ti[i]){
            count++;
            if(count % zi[i] == 0){
                j += yi[i];
            }
        }
        // cout << i << " " << countB[i] << endl;
        countB[i] = count;
        ballons += count;
    }
    return (ballons >= m);
}

void work(){
    // Children Holiday.
    cin >> m >> n;
    ti.resize(n);
    zi.resize(n);
    yi.resize(n);
    countB.resize(n);
    for(int i = 0;i < n;i++){
        cin >> ti[i] >>zi[i] >> yi[i];
    }
    if(m == 0){
        cout << 0 << endl;
        for(int i = 0;i < n;i++){
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    ll l = 0;
    ll r = 1;
    while(!good(r)) r *= 2;
    while(r > l + 1){
        ll mid = (l + r)/2;
        if(good(mid)){
            r = mid;
        }
        else l = mid;
    }
    cout << r << endl;
    bool ans = good(r);
    for(int i = 0;i < n;i++){
        cout << countB[i] << " ";
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


