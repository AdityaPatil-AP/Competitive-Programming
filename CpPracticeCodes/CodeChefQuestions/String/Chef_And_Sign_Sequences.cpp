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
    // Chef and Sign Sequences.
    // string s;
    // cin >> s;
    // ll ans = 1; // minimum answer is going to be 2.
    // ll curr = 1;
    // // I will keep another variable curr to track the 
    // // current number I am having.
    // for(int i = 0;i < s.size();i++){
    //     // Treat equal to as nothing and skip.
    //     if(s[i] == '=') continue;
    //     else if(s[i] == '<') curr++;
    //     else if(s[i] == '>'){
    //         if(ans == 1) ans = 2;
    //         curr = 1;
    //     }
    //     if(curr > ans) ans = curr;
    // }
    // cout << ans << endl;

    // Different answer
    string s;
    cin >> s;
    int curr = 0;
    int max = 0;
    char prev = s[0];
    int i = 0;
    while(i < s.size()){
        if(s[i] != '='){
            if(s[i] == prev){
                curr++;
            }
            else {
                if(curr > max){
                    max = curr;
                } 
                curr = 1;
            }
            prev = s[i];
        }
        i++;
    }
    if(curr > max){
        max = curr;   
    }
    cout << max + 1 << endl;
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


