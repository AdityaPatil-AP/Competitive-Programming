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

// const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    int n; 
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    int exprcount = 0;
    for(int i = 0;i < n;i++){
        if((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
            mp[s[i]]++;
        }  
        if(s[i] == '+'){
            mp['+']++;
            exprcount++;
        }
        else{
            mp['-']++;
            exprcount++;
        }
    }
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    string ans = "";
    int i = 0, j = 9;
    while(i < (n - (2 * exprcount))){
        char m = j;
        int countm = mp[m];
        bool flag = false;
        for(int k = 0;k < countm;k++){
            if(i >= (n - (2 * exprcount))){
                flag = true;
                break;
            }
            ans += m;
            mp[m]--;
            i++;
        }
        if(flag) break;
        j--;
    }
    while(mp['+'] != 0 || mp['-'] != 0){
        if(mp['+'] != 0){
            ans += '+';
        }
        else{
            ans += '-';
        }
        int count = 0;
        while(count < 1){
            if(mp[(char)j] != 0){
                ans += (char)j;
                count++;
            }
            else{
                j--;
            }
        }
    }
    cout << ans << endl;
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


