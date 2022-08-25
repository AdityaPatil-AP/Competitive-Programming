#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int


void work(){
    // D. Black and White Ring Game
    int n;
    cin >> n;
    int count0, count1;
    count0 = count1 = 0;
    int found = 0;
    int prev;
    cin >> prev;
    int first = prev;
    prev == 1 ? count1++ : count0++;
    int curr;
    for(int i = 1; i < n;i++){
        cin >> curr;
        curr == 1 ? count1++ : count0++;
        if(prev == 1 && curr == 0){
            found++;
        }
        prev = curr;
    }
    if(first == 0 && curr == 1){
        found++;
    }
    int total = min(count0, count1);
    (total - found) % 2 == 0 ? cout << "Bob" : cout << "Alice";
    cout << endl;
}

int32_t main(){
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