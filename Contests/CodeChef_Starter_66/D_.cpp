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

void work()
{
    // My Try :
    // Palindrome in Making
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
	vector<ll> rev = arr;
	reverse(rev.begin(), rev.end());
	ll m = (n - 1)/2;
	ll j = 0;
	ll ans = 0;
	while(j <= m){
		if(arr[j] == rev[j]){
			j++;
		}
		else if(arr[j] > rev[j]){
			int i;
			ll min_difference = INT_MAX;
			for(i = j;i <= m;i++){
				if(arr[i] > rev[i]){
					min_difference = min(min_difference, arr[i] - rev[i]);
				}
				else break;
			}
			for(int k = j;k <= m && k <= (i - 1);k++){
				rev[k] += min_difference;
			}
			ans+=min_difference;
		}
		else if(arr[j] < rev[j]){
			int i;
			ll min_difference = INT_MAX;
			for(i = j;i <= m;i++){
				if(arr[i] < rev[i]){
					min_difference = min(min_difference, rev[i] - arr[i]);
				}				else break;
			}
			for(int k = j;k <= m && k <= (i - 1);k++){
				arr[k] += min_difference;
			}
			ans+=min_difference;
		}
	}
	cout << ans << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output1.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        work();
    }
    return 0;
}
