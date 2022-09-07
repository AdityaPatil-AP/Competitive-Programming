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

vector<int> primes;
bool prime[n + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            primes.pb(p);
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


void work(){
    // My Try : Wrong way
    // int d;
    // cin >> d;
    // vector<int> ans;
    // ans.push_back(1);
    // for(int i = 0;i <= primes.size();i++){
    //     if(primes[i] - ans.back() >= d){
    //         ans.push_back(primes[i]);
    //     }
    //     if(ans.size() == 3){
    //         break;
    //     }
    // } 
    // cout << 1ll * ans[1] * ans[2] << endl;

    // Editorial 
    int x;
    cin >> x;
    vector<int> p;
    for(int i = x + 1; ; i++){
        int t = 1;
        for(int j = 2;j * j <= i;j++){
            if(i % j == 0){
                t = 0;
                break;
            }
        }
        if(t){
            p.push_back(i);
            break;
        }
    } 
    for(int i = p.back() + x; ; i++){
        int t = 1;
        for(int j = 2;j * j <= i;j++){
            if(i % j == 0){
                t = 0;
                break;
            }
        }
        if(t){
            p.pb(i);
            break;
        }
    }
    cout << min(1ll * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << endl;
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


