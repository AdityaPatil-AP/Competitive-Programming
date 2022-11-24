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
    // Palindrome by Splitting.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    ll i = 0, j = arr.size() - 1;
	ll ans = 0;
	while(i <= j){
		if(arr[i] == arr[j]){
			i++, j--;
			continue;
		}
		else if(arr[i] > arr[j]){
			ll diff = arr[i] - arr[j];
			arr[i] = diff;
			// arr.insert(arr.begin() + i, arr[j]);
			// i++;
			j--;
			ans++;
		}
		else if(arr[j] > arr[i]){
			ll diff = arr[j] - arr[i];
			arr[j] = diff;
			// arr.insert(arr.begin() + j, diff);
			i++;
			ans++;
		}
	}
	cout << ans << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
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
