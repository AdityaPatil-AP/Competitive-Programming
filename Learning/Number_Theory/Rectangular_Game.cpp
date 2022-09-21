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

void work(){
    // Rectangular Game 
    int n;
    cin >> n;
    ll ans = n;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            ans += (n/i);
            n = n/i;
            i = 1;
            continue;
        }
    }
    if(n >= 2){
        ans += 1;
    }
    cout << ans << endl;
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

