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

#define MAXN   10000001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

map<int, int> prime_factorization(int n) {
    map<int, int> mp;
    while (n % 2 == 0) {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n]++;
    return mp;
}

vector<pair<int, int>> prime_factorisation(ll n){
    vector<pair<int, int>> factors;
    ll cnt = 0;
    while(n % 2 == 0){
        cnt++;
        n = n/2;
    }
    if(cnt != 0)
        factors.push_back({2, cnt});
    for(int i = 3;(i * i) <= n;i += 2){
        ll cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        if(cnt != 0) factors.push_back({i, cnt});
    }

    if(n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

void work(){
    // My Try : 
    // ll n;
    // cin >> n;
    // auto factors = prime_factorization(n);
    // // for(auto i : factors){
    // // 	cout << i.first << " " << i.second << " ";
    // // }
    // // cout << endl;
    // vector<ll> bases(factors.size());
    // vector<ll> powers(factors.size());
    // int i = 0;
    // for(auto it : factors){
    // 	bases[i] = it.first;
    // 	powers[i] = it.second;
    // 	i++;
    // }
    // ll count = factors.size();
    // ll ans = 0;
    // while(count){
    // 	ll curr = 1;
    // 	for(int i = 0;i < bases.size();i++){
    // 		if(powers[i] != 0){
    // 			curr *= bases[i];	
    // 			powers[i]--;
	// 			if(powers[i] == 0) count--;
    // 		}
    // 	}
    // 	// cout << curr << endl;
    // 	ans += curr;
    // }
    // cout << ans << endl;

    // Upsolving.
    ll n;
    cin >> n;
    vector<pair<int, int>> factors = prime_factorisation(n);
    ll count = factors.size();
    ll ans = 0;
    while(count){
        ll curr = 1;
        for(int i = 0;i < factors.size();i++){
            if(factors[i].second != 0){
                curr *= factors[i].first;
                factors[i].second--;
                if(factors[i].second == 0){
                    count--;
                }
            }
        }
        ans += curr;
    }
    cout << ans << endl;
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


