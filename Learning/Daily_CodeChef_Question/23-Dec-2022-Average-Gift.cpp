#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	// your code goes here
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n, 0);
        for(auto &x : arr) cin >> x;
        sort(arr.begin(), arr.end());
        if(x < arr[0] || (x > arr[n - 1])){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
	return 0;
}
