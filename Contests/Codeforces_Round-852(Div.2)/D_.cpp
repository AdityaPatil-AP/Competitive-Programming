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
    // My Try : Correct
    ll n;
    cin >> n;
    
    if(n % 2 == 0) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        int j = 1;
        for(int i = 2 * n;i > n;i -= 2){
            cout << i << " " << j++ << endl; 
        }

        for(int i = (2*n) - 1;j <= n;j++, i-=2){
            cout << j << " " << i << endl;
        }
    }
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

