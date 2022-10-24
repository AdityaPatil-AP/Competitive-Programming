#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int


// Using Binet's Formula
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

void work(){
    // My Try
    // Charges
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int distance = 0;
    for(int i = 1;i < s.size();i++){
        if(s[i] == s[i - 1]){
            distance += 2;
        }
        else {
            distance += 1;
        }
    }
    // Was coming wrong for only n == 1 wala case.
    // if(n == 1){
    //     while(k--){
    //         int index;
    //         cin >> index;
    //         cout << 0 << endl;
    //     }
    //     return;
    // }
    // cout << distance << endl;
    while(k--){
        int index;
        cin >> index;
        index--;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(index == 0){
            (s[index] == '1') ? s[index] = '0' : s[index] = '1';
            (s[index] == s[index + 1])? distance += (-1 + 2): distance += (-2 + 1);
        }
        else if(index == n - 1){
            (s[index] == '1') ? s[index] = '0' : s[index] = '1';
            (s[index] == s[index - 1])? distance += (-1 + 2): distance += (-2 + 1);
        }
        else{
            (s[index] == '1') ? s[index] = '0' : s[index] = '1';
            (s[index] == s[index - 1])? distance += (-1 + 2): distance += (-2 + 1);
            (s[index] == s[index + 1])? distance += (-1 + 2): distance += (-2 + 1);
        }
        cout << distance << endl;
    }
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


