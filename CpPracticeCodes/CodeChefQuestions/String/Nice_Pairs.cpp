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
    // Nice Pairs
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll count = 0;
    for(ll i = 0;i < n;i++){
        ll curr = s[i] - '0';
        for(ll j = i + 1;j <= i + 9;j++){
            ll next = s[j] - '0';
            if((j - i) == abs(curr - next)) count++;
        }
    }
    cout << count << endl;
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


