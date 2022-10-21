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
    // Median Minimisation
    ll n;
    cin >> n;
    vector<ll> arr(n, 0ll);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    ll median1 = arr[(n - 1)/2 - 1];
    ll median2 = arr[(n + 1)/2 - 1];
    // cout << median1 << " " << median2 << endl;
    ll ans = abs(median1 - median2);
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


