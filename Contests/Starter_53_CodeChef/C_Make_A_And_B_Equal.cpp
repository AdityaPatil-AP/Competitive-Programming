#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int


void work(){
    // B. Make A and B Equal
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    int suma, sumb;
    suma = sumb = 0;
    int difference = 0;
    for(int i = 0;i < n;i++){
        suma += a[i];
        sumb += b[i];
        difference += abs(a[i] - b[i]);
    }
    if(suma != sumb){
        cout << "-1" << endl;
    }
    else{
        cout << difference/2 << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}