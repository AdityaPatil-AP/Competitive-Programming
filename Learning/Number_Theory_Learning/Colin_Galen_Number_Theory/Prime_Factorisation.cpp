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

// Primes till n;
vector<int> pr;
bool primes[N + 1];
void sieve(){
    for(int i = 2;i * i<= N;i++){
        if(primes[i] == 0){
            pr.pb(i);
            for(int j = i * i;j <= N;j+=i){
                primes[j] = 1;
            }
        }
    }
}

vector<ll> factors(int x){
    vector<ll> ret;
    for(ll p : pr){ // precompute list of primes
        if(p * p > x){
            // checked all primes below p, now x can't be a product of two unchecked primes
            // since p^2 > x case work
            if(x > 1){
                ret.pb(x);
                x = 1;
            }
        }
        else{
            while(x % p == 0){ // take as much of this as we have
                ret.pb(p); 
                x /= p; // make sure you divide x, that makes the p^2 > x case work
            }
        }
    }
    return ret;
}

void work(){
    // Prime Factorisation;
    int n;
    cin >> n;
    vector<ll> ans = factors(n);
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    sieve();
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


