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

const int maxN = 88000001; 
bool is_prime[maxN];
vector<int> primes;
void sieve(){
    is_prime[0] = is_prime[1] = true;
    for(int i = 2;i * i <= maxN;i++){
        if(!is_prime[i]){
            for(int j = i * i;j <= maxN;j += i){
                is_prime[j] = true;
            }
        }
    }
    for(int i = 1;i <= maxN;i++){
        if(!is_prime[i]){
            primes.pb(i);
        }
    }
}

void work(){
    // 
    int k;
    cin >> k;
    cout << primes[k - 1] << endl;
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


