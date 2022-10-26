#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    // G)
    int n;
    cin >> n;
    string s;
    cin >> s;
    // First Occurence of 0.
    int i = 0;
    while(i < n && s[i] != '0'){
        i++;
    }
    if(i == n) {
        cout << 0 << endl;
        return;
    }
    // first Occurence of 1.
    int j = 0;
    while(j < n && s[j] != '1'){
        j++;
    }
    if(j == n){
         cout << 0 << endl;
         return;
     }
    int size = min(n - j, n - i);
    int i1 = i;
    // number of consecutive ones at the start
    while(i1 < n && s[i1] == '0'){
        i1++;
    }
    // cout << i1 << endl;
    int numZeroesC = i1 - i;
    int numCOnes = 0;
    int j1 = j;
    while((n - j1 - 1) >= size && s[j1] == '1'){
        j1++;
    }
    numCOnes = j1 - j;
    j += max(0, (numCOnes - numZeroesC));
    string a, b;
    for(;j < n && i < n;i++, j++){
        a += s[i];
        b += s[j];
    }
    string c;
    for(int i = 0;i < size;i++){
        int num = a[i] + b[i];
        if(num == 97){
            c[i] = '1';
        }
        else c[i] = '0';
    }
    ll ans = 0;
    for(int i = size - 1;i >= 0;i--){
        if(c[i] == '1')
            ans = (ans + (ll)(pow(2, (size - i - 1)))%mod)%mod;
    }
    cout << ans << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


