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
    // Valleys and Hills
    string ans = "";
    int n, m;
    cin >> n >> m;
    if(n > m){
        cout << 2 * n + 1 << endl;
        for(int i = 0;i < n;i++){
            ans.push_back('0');
            ans.push_back('1');
        }
        ans.push_back('0');
    }
    else if(m > n){
        cout << 2 * m + 1 << endl;
        for(int i = 0;i < m;i++){
            ans.push_back('1');
            ans.push_back('0');
        }
        ans.push_back('1');
    }
    else{
        cout << 2 * n + 2 << endl;
        for(int i = 0;i < n + 1;i++){
            ans.push_back('0');
            ans.push_back('1');
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


