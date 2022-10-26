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
    // A) Chef Score
    // int n, x, y;
    // cin >> n >> x >> y;
    // if(y % x == 0 && (y/x) <= n){
    //     cout << "YES" << endl;
    // }
    // else cout << "NO" << endl;
    // return;

    // Editorial
    // In the input 0 <= y <= n.x;
    // Which signifies that the number of questions are sufficent to 
    // to get y marks.
    ll n, x, y;
    cin >> n >> x >> y;
    if(y % x == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
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


