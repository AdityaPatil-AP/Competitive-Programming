#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cout << "Enter the number of rows : " << endl;
    cin >> n;
    int i, j;
    for(int i = 1;i <= 3 * n;i++){

        for(int j = 1;j <= (2 * n - 1);j++){
            if(i <= n){
                if(j >= 2 * n - i){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            else if(i <= 2 * n){
                if(j >= i || i - (n + j) >= 1){
                    cout << "*";
                }
                else if(j == n){
                    cout << "1";
                }
                else{
                    cout << " ";
                }
            }
            else if(j <= 3 * n){
                if(((3*n) - i) + 1 >= j){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
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


