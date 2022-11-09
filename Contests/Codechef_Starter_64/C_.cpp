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
    // 
    ll n;
    cin >> n;
    vector<ll> arr(2 * n, 0);
    for(auto &x : arr) cin >> x;
    map<int, int> mp;
	sort(arr.begin(), arr.end());
    for(int i = 0;i < 2 * n;i++){
    	mp[arr[i]]++;
    }
    int max_freq = 0;
    for(auto i : mp){
    	max_freq = max(max_freq, i.second);
    }
    int others = 2 * n - max_freq;
	if((max_freq - others) > 0 && (max_freq - others)/2 > others + 1){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
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
