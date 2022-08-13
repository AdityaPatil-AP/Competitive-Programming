#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n, x;
    cin >> n >> x;
    // if(x < n){
    //     cout << "-1" << endl;
    // }
    // else{
    //     if(x == n){
    //         for(int i = 1;i <= n;i++){
    //             cout << i << " ";
    //         }
    //         cout << endl;
    //     }
    //     else{
    //         int m = x - n;
    //         cout << m + 1 << " ";
    //         for(int i = 1;i <= n;i++){
    //             if(i != (m + 1)){
    //                 cout << i << " ";
    //             }
    //         }
    //         cout << endl;
    //     }
    // }

    // Editorialist Solution
    if(x < n){
        cout << "-1" << endl;
        return;
    }
    x -= (n - 1);
    cout << x << " ";
    for(int i = 1;i <= n;i++){
        if(i == x){
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
    return;
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