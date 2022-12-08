#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 998244353
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

void work()
{
    // My Try :
    // xor product.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
	ll ans = 1;
	// cout << ans << endl;
	ll count1 = count(arr.begin(), arr.end(), 1);
	// cout << count1 << endl;
	int nOnes = count1;
	for(int i = 0;i < arr.size();i++){
		// if(arr[i] == 1){
		// 	// for(int i = 1;i <= 30;i++){
		// 	// 	if(find(arr.begin(), arr.end(), pow(2, i)) != arr.end()){
		// 	// 		ans = (ans * (ll)((pow(2, i)) + 1))%mod;
		// 	// 		arr.erase(find(arr.begin(), arr.end(), pow(2, i)));
		// 	// 	}
		// 	// }
		// 	int index = std::lower_bound(arr.begin(), arr.end(), 2) - arr.begin();
		// 	for(int j = index;j < arr.size();j++){
		// 		if((arr[j] ^ 1) > arr[j]){
		// 			// cout << j << " inside " << endl;
		// 			ans = (ans * (arr[j] ^ 1))%mod;
		// 			arr.erase(arr.begin() + j);
		// 			break;
		// 		}
		// 	}
		// }
		// else ans = (ans * arr[i])%mod;
		// // cout << ans << " " << i << endl;
		if(arr[i] != 1 && arr[i] % 2 == 0 && nOnes > 0){
			ans = (ans * (++arr[i]))%mod;
			nOnes--;
		}
		else ans = (ans * arr[i])%mod;
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
