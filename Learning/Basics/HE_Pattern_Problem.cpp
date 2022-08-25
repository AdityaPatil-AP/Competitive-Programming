#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Pattern Problem
    int i, j;
    int n;
    cin >> n;
    for(i = 1;i <= (2 * n - 1);i++){
        for(j = 1;j <= (2 * n - 1);j++){
            if(j < n){
                if(i == j && i < n){
                    cout << i;
                }
                else if(i > n && (2 * n - i == j)){
                    cout << 2 * n - i;
                }
                else{
                    cout << " ";
                }
            }
            else if(j==n && j == i){
                cout << i;
            }
            else if(j > n){
                if((n - i) == (j - n) && i <  n){
                    cout << i;
                }
                else if(2 * n - i == 2 * n - j){
                    cout << 2 * n - i;
                }
                else{
                    cout << " ";
                }
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


