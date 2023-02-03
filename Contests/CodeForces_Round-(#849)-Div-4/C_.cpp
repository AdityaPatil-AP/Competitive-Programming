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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = n - 1;
    while(i < j){
        if((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0')){
            i++, j--;
        }
        else break;
    }
    if(i == j){
        cout << 1 << endl;
    }
    else if(j < i){
        cout << 0 << endl;
    }
    else {
        cout << (j - i + 1) << endl;
    }
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


