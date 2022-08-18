#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

void work(){
    int n;
    cin >> n;
    if(n % 2){
        cout << 1 << " ";
        for(int i = 2;i <= n;i+=2){
            cout << i + 1 << " " << i << " ";
        }
    }
    else{
        for(int i = 1;i <= n;i+=2){
            cout << i + 1 << " " << i << " ";
        }
    }
    cout << endl;
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