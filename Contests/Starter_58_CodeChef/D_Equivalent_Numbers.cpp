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

vector<int> factorial(14, 1);
void fact(){
    for(int i = 1;i <= 14;i++){
        factorial[i] = factorial[i - 1] * i;
    }
    return;
}

vector<pair<int, int>> primeFactors(int a){
    vector<pair<int, int>> primePower;
    for(int i = 2; i * i <= a;i++){
        if(a % i == 0){
            int count = 0;
            while(a % i == 0){
                a = a/i;
                count++;
            }
            primePower.push_back({i, count});
        }
    }
    if(a > 1){
        primePower.push_back({a, 1});
    }
    return primePower;
}

void work(){
    // My Try :
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>> res1 = primeFactors(a);
    vector<pair<int, int>> res2 = primeFactors(b);
    if(res1.size() != res2.size()){
        cout << "NO" << endl;
        return;
    }
    double equivalency = (double)res1[0].second/res2[0].second;
    for(int i = 0;i < res2.size();i++){
        if(res1[i].first != res2[i].first || equivalency != (double)res1[i].second/res2[i].second){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact();
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


