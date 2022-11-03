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
    // Editorial.
    // Combinatorics + Maximum Sum Subarray.
    string s;
    cin >> s;
    int n = s.size();
    // for storing each 1's contribution without flips.
    vector<ll> b(n, 0ll);
    // for calculating the Maximum Sum Subarray.
    vector<ll> c(n, 0ll);
    ll sum = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '1'){
            b[i] = 1ll * (i + 1) * (n - i) * 1ll;
            c[i] = -(1ll * (i + 1) * (n - i) * 1ll);
            sum += b[i];
        }
        else{
            c[i] = (i + 1) * (n - i) * 1ll;
        }
    }
    // finding the maximum sum subarray.
    ll max_sum = 0, curr_sum = 0;
    for(int i = 0;i < n;i++){
        curr_sum += c[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        if(curr_sum > max_sum){
            max_sum = curr_sum;
        }
    }
    if(curr_sum > max_sum){
        max_sum = curr_sum;
    }
    cout << (sum + max_sum) << endl;
    return;
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


