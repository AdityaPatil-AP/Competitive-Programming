#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

void work(){
    // My Try
    // Different String.
    ll x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    // Find a Suitable Position, if Possible where i can keep 
    // my black knight.
    // So we would iterate over all the positions.
    // Check if at that position, is our black Knight able to kill
    // both the white pieces simultaneously.
    // determines if we have find such a favourable position.
    bool flag = false;
    for(int i = 1;i <= 8;i++){
        // If the white pieces and the black knight are in the 
        // same row then the black knight in never going to attack 
        // the white piece, so we continue.
        if(i == x1 || i == x2) continue;
        for(int j = 1;j <= 8;j++){
            // Similarly black knight cannot have same columns as that
            // of the white pieces.
            if(j == y1 || j == y2) continue;
            // Checking if knight can kill both the white pieces 
            // simultaneously.
            if(abs(i - x1) * abs(j - y1) == 2 && abs(i - x2) * abs(j - y2) == 2){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


