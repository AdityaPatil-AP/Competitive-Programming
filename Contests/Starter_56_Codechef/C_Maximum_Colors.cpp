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

vector<int> arr;

void work(){
    // Maximum Colors
    arr.resize(3);
    for(auto &x : arr) cin >> x;
    // for(auto x : arr) cout << x << " ";
    // cout << endl;
    sort(arr.rbegin(), arr.rend());
    int ans = 0;
    for(int i = 0;i < 3;i++){
        if(arr[i] > 0){
            ans += 1;
            arr[i] -= 1;
        }
    }
    // for(auto x : arr) cout << x << " ";
    // cout << endl;
    for(int i = 0;i < 2;i++){
        if(arr[i] > 0){
            for(int j = i + 1;j < 3;j++){
                // cout << arr[i] << " " << arr[j] << endl;
                if(arr[i] >= 1 && arr[j] >= 1){
                    ans += 1;
                    arr[i] -= 1;
                    arr[j] -= 1;
                }
            }
        }
    }
    cout << ans << endl;
    // arr.clear();
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


