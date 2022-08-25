#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int row;
    cout << "Enter the number of rows : " << endl;
    cin >> row;
    int number, k = 1;
    int i, j;
    for(i = 1;i <= row;i++){
        int number = k;
        for(j = 1;j <= i;j++){
            cout << number;
            number -= (row + j) - i;
        }
        k += (row - i) + 1;
        cout << endl;
    }
    // int i, j, row;
    // cout << "Enter the number of rows : " << endl;
    // cin >> row;
    // int number, k = 1;
    // for(int i = 1;i <= row;i++){
    //     number = k;
    //     for(int j = 1;j <= i;j++){
    //         cout << number; 
    //         number -= (row + j) - i;
    //     }
    //     k = k + (row + 1) - i;
    //     cout << endl;
    // }
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


