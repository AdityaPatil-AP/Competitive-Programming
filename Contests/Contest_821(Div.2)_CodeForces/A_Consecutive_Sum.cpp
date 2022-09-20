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
int k;
// bool comp(int a, int b){
//     if(a%k == b%k){
//         return true;
//     }
//     return false;
// }

void work(){
    // My Try :
    int n;
    cin >> n >> k;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    int temp = k;
    for(int i = 0;i < k;i++){
        for(int j = i + k;j < n;j += k){
            if(arr[i] < arr[j] && temp > 0){
                swap(arr[i], arr[j]);
                temp--;
            }
        }
    }
    ll sum = 0;
    for(int i = 0;i < k;i++){
        sum += arr[i];
    }
    cout << sum << endl;
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


