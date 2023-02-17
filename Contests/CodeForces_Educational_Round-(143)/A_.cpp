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
    // My Try : Correct
    ll n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    if(s1[n - 1] != s2[m - 1]){
        int count = 1;
        bool countGreater2 = false;
        map<ll, ll> mp;
        for(int i = 1;i < n;i++){
            if(s1[i] == s1[i - 1]){
                count++;
                if(count == 3){
                    countGreater2 = true;
                    break;
                }
            }
            else{
                mp[count]++;
                count = 1;
            }
        }

        mp[count]++;
        count = 1;
        for(int i = 1;i < m;i++){
            if(s2[i] == s2[i - 1]){
                count++;
                if(count == 3){
                    countGreater2 = true;
                    break;
                }
            }
            else{
                mp[count]++;
                count = 1;
            }
        }
        mp[count]++;
        if(countGreater2){
            cout << "NO" << endl;
            return;
        }
        ll badCount = 0;
        for(auto it : mp){
            if(it.first == 2) badCount = it.second;
        }
        // cout << badCount << endl;
        if(badCount > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    else{
        bool isAlternate1 = true;
        bool isAlternate2 = true;

        for(int i = 1;i < n;i++){
            if(s1[i] == s1[i - 1]){
                isAlternate1 = false;
                break;
            }
        }
        for(int i = 1;i < m;i++){
            if(s2[i] == s2[i - 1]){
                isAlternate2 = false;
                break;
            }
        }
        if(isAlternate1 && isAlternate2){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
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

