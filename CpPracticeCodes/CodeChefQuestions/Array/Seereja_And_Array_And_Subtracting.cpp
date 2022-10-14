#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

ll findGcd(ll a, ll b){
	return (b == 0) ? a : findGcd(b, a % b);
}

void work(){
    // My Try
    // Seereja and array and Subtracting.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(ll &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
 	// If we compare we subtract till they become equal, 
	// if one becomes less than the other then we are again
	// subtracting the values from one another.
	// And that value where both of them becomes equal is the 
	// their greatest common divisor. So if all the elements 
	// have to stop subtracting they have to meet at some common 
	// value and that is the gcd of the whole array.
	ll gcd = arr[0];
	for(ll i = 1;i < n;i++){
		gcd = findGcd(arr[i], gcd);
	}
	cout << (n * gcd) << endl;
    return; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


