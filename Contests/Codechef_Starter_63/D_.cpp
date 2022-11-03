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

pair<ll, ll> solve(int index, string &a, string &b, vector<pair<ll, ll>> &dp){
	if(index == a.size()){
		return {0, 0};
	}
	if(dp[index].first != INT_MAX){
		return dp[index];
	}
	pair<ll, ll> ans;
	ll difference;
	if(b[index] > a[index]){
		difference = (int)b[index] - (int)a[index];
	}
	else{
		difference = (26 - ((int)a[index] - (int)b[index]));
	}
	auto smallans = solve(index + 1, a, b, dp);
	ll a1 = difference + smallans.first;
	ll b1 = difference + smallans.second;
	if(abs(a1) < abs(b1)){
		ans.first = a1;
	}
	else{
		ans.first = b1;
	}
	ll c = smallans.first - (26 - difference);
	ll d = smallans.second - (26 - difference);
	if(abs(c) <= abs(d)){
		ans.second = c;
	}
	else ans.second = d;

	return dp[index] = ans; 
}

void work(){
    // My Try :
    // 
    // ll n;
    // cin >> n;
    // string a, b;
    // cin >> a >> b;
    // pair<ll, ll> minans;
    // vector<pair<ll, ll>> dp(n, {INT_MAX, INT_MAX});
    // minans = solve(0, a, b, dp);
    // cout << min(abs(minans.first), abs(minans.second)) << endl;

    // Editorial..
    // Didn't Needed the recursive solution.
    // Can be done with some Intuition and Maths as Well.
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    // First we will calculate the score we achieve if we just do
    // right rotations.
    ll ans = 0;
    for(int i = 0;i < n;i++){
    	if(a[i] <= b[i]){
    		ans += (b[i] - a[i]);
    	}
    	else {
    		ans += (26 + (b[i] - a[i]));
    	}
    }
    ans = (ans % 26);
    cout << min(ans, (26 - ans)) << endl;
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


