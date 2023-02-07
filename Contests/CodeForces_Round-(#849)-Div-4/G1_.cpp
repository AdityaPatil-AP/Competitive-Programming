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

    ll n, c;
    cin >> n >> c;

    vector<ll> arr(n , 0);
    for(auto &x : arr) cin >> x;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0;i < arr.size();i++){
        pq.push((i + 1 + arr[i]));
    }
    int count = n;
    ll ans = 0;
    while(!pq.empty()){
        ll curr = pq.top();
        pq.pop();
        if(c >= curr){
            c -= curr;
            ans++;
        }
        else break;
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


