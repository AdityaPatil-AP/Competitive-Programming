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

const int N = 10000005;
#define pb push_back

// Prime Factorisation - Brute Force Approach
// Time Complexity - O(n) - when we have n as a prime number
void primeFactB(int n){
    for(int i = 2;i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++, n /= i;
            }
            cout << i << "^" << cnt << endl;
        }
    }
    return;
}

void primeFactOpti(int n){
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++, n /= i;
            }
            cout << i << "^" << cnt << endl;
        }
    }
    if(n > 1) {
        cout << n << "^" << 1 << endl;
    }
    return;
}

void work(){
    // Prime Factorization using Brute Force Approach.
    primeFactB((ll)6469693230/29);

    // Prime Factorisation using Optimised Approach.
    primeFactOpti(32);
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


