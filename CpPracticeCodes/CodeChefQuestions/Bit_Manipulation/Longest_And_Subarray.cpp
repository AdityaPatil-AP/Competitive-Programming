#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

void work(){
    // My Try
    // Longest AND Subarray
	ll n;
	cin >> n;
	ll i = 0;
	if(n == 1){
		cout << 1 << endl;
		return;
	}
	while((1 << i) <= n){
		i++;
	}
	ll prev = 1,curr = 1;
	if(i - 2 >= 0){
		prev = (1 << (i - 1)) - (1 << (i - 2));
	}
	curr = n - (1 << (i - 1)) + 1;
	ll ans = max(curr, prev);
	cout << ans << endl;
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


