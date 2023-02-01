#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
	    ll n, k;
	    cin >> n >> k;
	    ll ans = pow(4, n) - 3 * pow(2, n) + 2;
	    cout << ans << endl;
	}
	return 0;
}
