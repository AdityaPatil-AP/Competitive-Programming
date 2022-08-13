#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // int x, y;
    // cin >> x >> y;
    // int distance = abs(x - y);
    // if(distance % 2 == 0){
    //     cout << distance/2 << endl;
    // }
    // else{
    //     cout << distance/2 + 1 << endl;
    // }

    // another method 
    int x, y;
    cin >> x >> y;
    cout << ceil((max(x, y) - min(x, y))/2.0f) << endl;
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