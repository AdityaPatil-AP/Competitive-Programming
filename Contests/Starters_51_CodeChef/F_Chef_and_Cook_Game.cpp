#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

void work(){
    // Editors Solution
    // Game Theory - Nim Game;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        if(x & 1){
            ans ^= (n - i);
        }
    }
    if(ans == 0){
        cout << "Cook" << endl;
    }
    else{
        cout << "Chef" << endl;
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