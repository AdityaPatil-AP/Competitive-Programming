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
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
	ll maxf = 1 ;
	map<ll, ll> mp;
	for(auto it : arr){
		mp[it]++;
	}
	ll ans = 0;
	ll currf = 1;
	ll freq = 1;
	for(int i = 0;i < arr.size();){
		ll curr = arr[i];
		ll j = i;
		while(i < arr.size() && arr[i] == curr){
			i++;
		}
		freq = i - j;
		maxf = max(maxf, freq);
		if(i < arr.size() && arr[i] != (curr + 1)){
			ans += freq;
		}
	}
	ans += maxf;
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


