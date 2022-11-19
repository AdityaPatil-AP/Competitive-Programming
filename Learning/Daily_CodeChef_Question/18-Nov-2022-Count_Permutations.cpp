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

int power(int base, int po){
    if(po == 0) return 1;
    ll temp = power(base, po/2)%mod;
    temp = (temp * temp)%mod;
    if(po%2){
        return ((ll)base * temp)%mod;
    }
    return (temp)%mod;
}

void work(){
    // Count Permutations.
    ll n;
    cin >> n;

    if(n <= 2){
        cout << 0 << endl;
    }
    else{
        ll ans = (power(2, n - 1) - 2 + mod)%mod;
        cout << ans << endl;
    }
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


