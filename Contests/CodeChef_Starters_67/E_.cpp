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


ll getBit(ll num, ll bit){
    return (num & (1 << bit));
}


void work()
{
    // My Try :
    // Existence of X.
    // ll a, b, c;
    // cin >> a >> b >> c;
    // ll ans = 0;
    // ll count = 0;
    // ll carry = 0;
    // while(a != 0 || b != 0 || c != 0){
    //     ll arem = a%2;
    //     ll brem = b%2;
    //     ll crem = c%2;
    //     // eight cases.
    //     if(arem == 0 && brem == 0 && crem == 0){
    //         carry = 1;
    //     }
    //     else if(arem == 0 && brem == 0 && crem == 1){
            
    //     }
    //     else if(arem == 0 && brem == 1 && crem == 0){

    //     }
    //     else if(arem == 0 && brem == 1 && crem == 1){

    //     }
    //     else if(arem == 1 && brem == 0 && crem == 0){

    //     }
    //     else if(arem == 1 && brem == 0 && crem == 1){

    //     }
    //     else if(arem == 1 && brem == 1 && crem == 0){

    //     }
    //     else if(arem == 1 && brem == 1 && crem == 1){

    //     }
    //     a /= 2;
    //     b /= 2;
    //     c /= 2;
    // }
    // if(carry != 1)
    //     cout << "YES" << endl;
    // else 
    //     cout << "NO" << endl;


    // Editorial Code.
    // Existence of X.
    ll a, b, c;
    cin >> a >> b >> c;
    ll carry = 0;
    for(int i = 0;i < 28;i++){
        ll checka = getBit(a, i), checkb = getBit(b, i), checkc = getBit(c, i);
        // cout << checka << " " << checkb << " " << checkc << endl;
        if(checka == checkb && checkb != checkc){
            carry ^= 1;
        }
    }
    if(carry) cout << "NO" << endl;
    else cout << "YES" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        work();
    }
    return 0;
}
