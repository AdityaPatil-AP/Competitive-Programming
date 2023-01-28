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
    ll n, s, r;
    cin >> n >> s >> r;
    cout << s - r << " ";
    n = n - 1;
    if(r % n == 0){
        for(int i = 0;i < n;i++){
            cout << (r/n) << " ";
        }
    }
    else{
       ll maxi = s - r;
        for(int i = 0;i < n;i++){
           for(int m = maxi;m >= 1;m--){
              if((r - m) >= (n - (i + 1))){
                 cout << m << " ";
                 r -= m;
                 break;
              }
           }
        }
    }
    cout << endl;
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


