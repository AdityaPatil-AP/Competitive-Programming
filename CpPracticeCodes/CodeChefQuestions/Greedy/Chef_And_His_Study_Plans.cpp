#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int
#define mod 1000000007

// Using Binet's Formula
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

bool comp(vector<int>&a, vector<int>&b){
    return a[1] <= b[1];
}

void work(){
    // My Try
    // Chef and His Study Plans.
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for(int i = 0;i < n;i++){
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    while(q--){
        int startq, endq;
        cin >> startq >> endq;
        int freeAt = 0; // tells us we are free at which time.
        for(int i = 0;i < n;i++){
            if(freeAt <= v[i][0]){
                ans++;
                freeAt = v[i][1];
            }
        }
    }
    return; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


