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
    // My Try :
    // A) 
    int a, b, c;
    cin >> a >> b >> c;
    bool oddP = false, evenP = false;
    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
        oddP = true;
    }
    if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0){
        evenP = true;
    }
    if(oddP && evenP) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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


