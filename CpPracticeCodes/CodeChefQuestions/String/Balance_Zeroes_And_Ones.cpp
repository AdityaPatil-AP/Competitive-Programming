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
    // Subarray GCD
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // Calculating Initially present number of 1s and 0s.
    int n1 = 0, n0 = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '1') n1++;
        else if(s[i] == '0') n0++;
    }
    string ans = "";
    for(int i = 0;i < n;i++){
        if(s[i] == '1') ans += '1';
        else if(s[i] == '0') ans += '0';
        else{
            if(n0 < n1){
                ans += '0';
                n0++;
            }
            else if(n1 < n0){
                ans += '1';
                n1++;
            }
            else {
                ans += '1';
                n1++;
            }
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


