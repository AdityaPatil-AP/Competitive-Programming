#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

bool isPalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

bool isPalindrome(string &s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

void work(){
    // My Try
    // Pairwise Xors
    // There can be no odd numbers generated from this 
    // procedure.
    ll n;
    cin >> n;
    if(n & 1 || n < 6){
        cout << "-1" << endl;
        return;
    }
    ll a = 0, b = n/2,c;
    for(ll i = 1;i < 30;i++){
        c = (1 << i);
        if(((c & b) != 0) && (c != b)){
            cout << a << " " << b << " " << c << endl;
            return;   
        }
    }
    cout << "-1" << endl;
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


