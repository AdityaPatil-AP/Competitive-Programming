#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d>> p >> nl >> np;
	int drinks = (k*l)/nl;
	int slices = (c * d);
	int salt = (p/np);
	int toastMade = min(drinks, min(slices, salt));
	int toastEach = toastMade/n;
	cout << toastEach;
}

// Basic Implementation Based.

// Direct ek baar read karo.
// Don't give up.
// It's easy starting ke problems just read till 
// the end and 
// asses the input and output and how it is behaving.
