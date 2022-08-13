#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

void multiply(ll A[2][2], ll M[2][2]){
	int fValue = ((A[0][0] * M[0][0])%mod +  (A[0][1] * M[1][0])%mod)%mod;
	int sValue = ((A[0][0] * M[0][1])%mod + (A[0][1] * M[1][1])%mod)%mod;
	int tValue = ((A[1][0] * M[0][0])%mod + (A[1][1] * M[1][0])%mod)%mod;
	int lValue = ((A[1][0] * M[0][1])%mod + (A[1][1] * M[1][1])%mod)%mod;
	A[0][0] = fValue;
	A[0][1] = sValue;
	A[1][0] = tValue;
	A[1][1] = lValue;
	return;
} 

void power(ll A[2][2], ll n){
	if(n == 1 || n == 0){
		return;
	}
	power(A, n/2);
	multiply(A, A);
	if(n%2 != 0){
		ll M[2][2] = {{1, 1}, {1, 0}};
		multiply(A, M);
	}
}

int fib(ll n){
	ll A[2][2] = {{1, 1}, {1, 0}};
	if(n == 0){
		return 0;
	}
	power(A, n - 1);
	return A[0][0]%mod;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll nStairs;
	cin >> nStairs;
	cout << fib(nStairs + 1) << endl;
	
	return 0;
}