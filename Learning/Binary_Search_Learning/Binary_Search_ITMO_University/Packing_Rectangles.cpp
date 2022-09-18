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

const int N = 10000005;
#define pb push_back

ll w, h, n;


bool good(ll x){
    return ((x/w) * (x/h)) >= n;
}

void work(){
    // Packing Rectangles
    cin >> w >> h >> n;
    ll r = 1;
    while(!good(r)) r *= 2; // r is good.
    ll l = 0; // this determines bad, we cannot put rectangles in square of size 0.
    while(r > l + 1){
        ll m = (l + r)/2;
        if(good(m)){
            r = m;
        }
        else l = m;
    }
    cout << r << endl;
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


