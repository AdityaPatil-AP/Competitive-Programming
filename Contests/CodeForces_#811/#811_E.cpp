#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

int next(int &num){
    return num + (num % 10);
}

void work(){
    // My Successful Attempt
    // Not able to do the Solution During the contest

    // Editor Solution
    int n;
    cin >> n;
    vector<int> vec(n);
    // First let's consider for the case of 5;
    bool flag5 = false;
    for(int i = 0;i < n;i++){
        cin >> vec[i];
        if(vec[i] % 5 == 0){
            vec[i] = next(vec[i]);
            flag5 = true;
        }
    }
    if(flag5){
        if(*min_element(vec.begin(), vec.end()) == *max_element(vec.begin(), vec.end())){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        bool flag2 = false, flag12 = false;
        for(int i = 0;i < n;i++){
            int num = vec[i];
            while(num % 10 != 2){
                num = next(num);
            }
            if(num % 20 == 2){
                flag2 = true;
            }
            else{
                flag12 = true;
            }
        }
        cout << ((flag2 & flag12) ? "NO" : "YES") << endl;
    }
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