#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int


void work(){
   // Gritty Grid;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int stb = (n - 1 + m - 1);
    if(x % 2 == 0 && stb % 2 == 1 && y % 2 == 0){
        cout << "No" << endl;
    }
    else if(x % 2 != 0 && y%2 != 0 && stb % 2 == 0){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return;
}

int32_t main(){
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


