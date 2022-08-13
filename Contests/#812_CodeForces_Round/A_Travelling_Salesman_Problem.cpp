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
    int up = 0, down = 0, right = 0, left = 0;
    for(int i = 0;i < n;i++){
        int xi, yi;
        cin >> xi >> yi;
        if(xi == 0){
            if(yi >= 0){
                up = max(up, yi);
            }
            else{
                down = max(down, abs(yi));
            }
        }
        else{
            if(xi >= 0){
                right = max(right, xi);
            }
            else{
                left = max(left, abs(xi));
            }
        }
    }
    cout << 2 * (up + down + left + right) << endl;
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