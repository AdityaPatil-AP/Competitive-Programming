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

const int n = 100001;
bool prime[n + 1] = {0};
vector<int> pr;

void sieve(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2;i * i <= n;i++){
        if(prime[i] == 0){
            for(int j = i * i;j <= n;j+=i){
                prime[j] = 1;
            }
        }
    }
    for(int i = 0;i <= n;i++){
        if(prime[i] == 0){
            pr.pb(i);
        }
    }
    return;
}

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n;i = i + 6){
        if(n % i == 0 || n % (i+2) == 0){
            return false;
        }
    }
    return true;
}

void work(){
    // NoldBack Problem
    int n, k;
    cin >> n >> k;
    int count = 0;
    for(int i = 0;;i++){
        int num = pr[i] + pr[i + 1] + 1;
        if(num > n){
            break;
        }
        if(prime[num] == 0){
            count++;
        }
    }
    (count >= k) ? cout << "YES" : cout << "NO";
    // cout << endl;
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
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


