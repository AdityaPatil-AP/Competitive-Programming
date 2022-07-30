#include<bits/stdc++.h>
using namespace std;

int fib(int  n){
	if(n <= 1){
		return n;
	}
	int last = fib(n - 1);
	int sLast = fib(n - 2);
	return last + sLast;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}