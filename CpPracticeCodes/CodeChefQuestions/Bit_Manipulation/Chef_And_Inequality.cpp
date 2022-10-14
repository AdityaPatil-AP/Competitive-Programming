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
    // Chef and Inequality.
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(ll x = a; x <= b;x++){
        ll y = max(c, x + 1);
        if(y <= d){
            ans += (d - y + 1);
        }
    }
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


