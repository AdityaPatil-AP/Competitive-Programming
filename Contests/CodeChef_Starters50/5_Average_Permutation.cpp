#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long long double

void work(){
    // My Solution
    // int n;
    // cin >> n;
    // cout << n << " ";
    // cout << n - 2 << " ";
    // for(int i = 1;i <= n - 3;i++){
    //     cout << i << " ";
    // } 
    // cout << n - 1 << endl;

    // Editorialist Solution
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    int s(0), e(n - 1);
    int cnt = n;
    while(s < e){
        vec[s++] = cnt--;
        vec[e--] = cnt--;
    }
    if(n % 2 == 1){
        vec[s] = cnt;
    }
    for(int x : vec){
        cout << x << " ";
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

