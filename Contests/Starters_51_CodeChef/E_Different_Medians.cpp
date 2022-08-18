#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // After the contest correct try
    int n;
    cin >> n;
    int start = 1, end = n;
    while(start <= end){
        if(start == end){
            cout << start << " ";
            break;
        }
        cout << end << " " << start << " ";
        start++;
        end--;
    }
    cout << endl;

    // Editor Solution
    // Same as my Solution.
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