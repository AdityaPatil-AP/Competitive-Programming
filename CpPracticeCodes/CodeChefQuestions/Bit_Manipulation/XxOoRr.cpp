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
    // XxOoRr
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;
    vector<ll> freq(32, 0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 32;j++){
            if((arr[i] >> j) & 1){
                freq[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i < 32;i++){
        if(freq[i] != 0){
            ans += freq[i] / k;
            freq[i] = freq[i] % k;
        }
        if(freq[i]) {
            ans++;
            freq[i]=0;
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


