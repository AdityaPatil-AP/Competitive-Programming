#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

bool ok = true;
int ans = 0;

void Find(int a, int b, string &text, vector<string> &str, vector<pair<int, int>> &match){
    int MAX = 0, id = -1, pos = -1; // MAX denotes the length of characters matched at max
    for(int i = a;i <= b;i++){
        for(int j = 0;j < len(str);j++){
            string s = str[j];
            if(i + len(s) <= b && i + len(s) > len(text)) continue;
            if(text.substr(i, len(s)) == s){
                if(i + len(s) > MAX){
                    MAX = i + len(s);
                    id = j;
                    pos = i;
                }
            }
        } 
    }
    if(id == -1){
        ok = false;
        return;
    }
    else{
        match.emplace_back(id, pos);
        ans++;
        if(MAX == len(text)) return;
        else Find(max(b + 1, pos + 1), MAX, text, str, match);
    }
}


void work(){
    // My Successful Attempt
    // Not able to do the Solution During the contest

    // Editor Solution
    ok = true;
    ans = 0;

    string text;
    cin >> text;

    int n;
    cin >> n;
    vector<string> str(n);
    forn(i, n){
        cin >> str[i];
    }
    vector<pair<int, int>> match;

    Find(0, 0, text, str, match);
    if(!ok){
        cout << "-1" << endl;
        return;
    }
    else{
        cout << ans << endl;
        for(auto &x : match){
            cout << x.first + 1 << " " << x.second + 1 << endl;
        }
    }
}

int main(){
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