#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back


void work(){
    // My Try : Wrong Answer
    // int mean, median;
    // cin >> mean >> median;
    // int x;
    // if(median >= 0){
    //     x = 3 * mean - (2 * median + 1);
    //     cout << x << " " << median << " " << median + 1 << endl;
    // }
    // else{ 
    //     x = 3 * mean - (2 * median - 1);
    //     cout << median - 1 << " " << median << " " << x << endl;
    // }
    
    // if(mean < median){
    //      int x = (3 * mean) - (median - 100);
    //     cout << -100 << " " << median << " " << x << endl;
    // }
    // else{
    //      int x = (3 * mean) - (median - 100);
    //     cout << -100 << " " << median << " " << x << endl;
    // }

   // Editorial 
    int mean, median;
    cin >> mean >> median;
    int x = (3 * mean - 2 * median);
    if(x <= median){
        cout << x << " " << median << " " << median << endl;
    }
    else cout << median << " " << median << " " << x << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


