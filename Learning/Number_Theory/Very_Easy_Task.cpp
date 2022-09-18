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

ll n, x, y;

bool good(ll t){
    ll mini = min(x, y);
    ll maxi = max(x, y);
    ll copies = (((t/mini)) + ((t-mini)/maxi));
    return (copies >= n);
}

void work(){
    // Very Easy Task
    cin >> n >> x >> y;
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


