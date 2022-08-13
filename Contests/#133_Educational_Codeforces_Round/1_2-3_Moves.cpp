#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int

void work(){
    int n;
    cin >> n;
    if(abs(n % 3) == 0){
        cout << n/3 << endl;
    }
    else if(abs(n % 3) == 1){
        if(n == 1){
            cout << 2 << endl;
            return;
        }
        cout << abs(n - 4)/3 + 2 << endl;
    }
    else{
        cout << n/3 + 1 << endl;
    }
    return;
}

int32_t main(){
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