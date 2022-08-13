#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

void work(){
    // 
    int n;
    cin >> n;
    vector<int> vec(n);
    forn(i, n){
        cin >> vec[i];
    }
    int maximum = *max_element(vec.begin(), vec.end());
    bool ans = true;
    for(int i = n - 1;i >= 1;i--){
        if(vec[i] >= vec[i - 1] || (vec[i - 1] == maximum && (i - 1) != 0)){
            continue;
        }
        else{
            ans = false;
        }
    }
    cout << ((ans) ? "YES" : "NO") << endl;
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