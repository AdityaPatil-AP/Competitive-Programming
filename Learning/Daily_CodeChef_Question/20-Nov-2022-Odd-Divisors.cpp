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

ll solve(ll m){
    ll sum = 0;
    for(int i = 1;i * i <= m;i++){
        if(m % i == 0){
            if(i % 2) sum += i;
            if((m/i) % 2 && (m/i) != i){
                sum += (m/i);
            }
        }
    }
    return sum;
}

void work(){
    // Odd Divisors.
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for(int i = l;i <= r;i++){
        ans += solve((ll)i);
    }
    cout << ans << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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


