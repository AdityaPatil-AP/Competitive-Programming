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
    // My Try : 
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0;
    ll y = 0;
    bool ans = false;
    for(int i = 0;i < n;i++){
        if(s[i] == 'U') y += 1;
        if(s[i] == 'D') y -= 1;
        if(s[i] == 'R') x += 1;
        if(s[i] == 'L') x -= 1;

        if(x == 1 && y == 1){
            ans = true;
            break;
        }
     }
     if(ans) cout << "YES" << endl;
     else cout << "NO" << endl;
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


