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
    // Xor N Bonacci Subsequence.
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1, 0);
    int temp;
    int xo = 0;
    // I first analysed the F wala array.
    // Then I analysed the Prefix xor wala 
    // array.
    // Prefix Xor karte gya.
    for(int i = 0;i < n;i++){
        cin >> temp;
        xo ^= temp;
        arr[i + 1] = xo;
    }
    ll k;
    // I saw that the pattern was repeating itself.
    while(q--){
        cin >> k;
        cout << arr[k%(n + 1)] << endl;
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


