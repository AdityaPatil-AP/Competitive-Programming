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
    // Even Subarray Xor
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout << 2 * (i + 1) << " ";
    }
    cout << endl;
    for(int i = 0;i < n;i++){
        cout << 2 * (i + 1) + 1 << " ";
    }
    cout << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    // cout << "Hello World" << endl;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


