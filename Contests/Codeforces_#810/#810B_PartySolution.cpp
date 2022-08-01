#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
int x[MAXN], y[MAXN], a[MAXN], degree[MAXN];

void work(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        degree[i] = 0;
    }
    for(int i = 1;i <= m;i++){
        cin >> x[i] >> y[i];
        degree[x[i]]++;
        degree[y[i]]++;
    }
    int ans = INT_MAX;
    if(m % 2 == 0){
        ans = 0;
    }
    // If person having odd no. of friends delete the one which has
    // least unhappiness value.
    for(int i = 1;i <= n;i++){
        if(degree[i] % 2 == 1){
            ans = min(ans, a[i]);
        }
    }

    // in this case everyone have even no. friends. in that case
    // we have to delete the pair of friends which have minimum happiness 
    // combined.
    for(int i = 1; i <= m;i++){
        if(degree[x[i]] % 2 == 0 && degree[y[i]] % 2 == 0){
            ans = min(ans, a[x[i]] + a[y[i]]);
        }
    }

    cout << ans << endl;
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