#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

using ll = long long int;
#define ll long long int


ll binpow(ll a, ll b, ll c){
    if(b == 0) return 1;
    ll t = (a, b/2, c);
    if(b % 2) return (((t * t)%c * a) + c)%c;
    return ((t * t)%c + c)%c;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif

    // int n = -1e6 +1;
    // cout << n << endl;

    // ll a = binpow(2, 200, 1e18);
    // cout << (1LL << 63)   << endl;
    int a = 'c' - '0';
    cout << a << endl;
    int x = 5;
    vector<pair<int,int>> v1 = {{0, 0}, {0, x}, {x, 0}, {x, x}};
    for(int i = 0;i <= 3;i++){
        cout << v1[i].first <<  " "  << v1[i].second << endl;
    }
    return 0;
}