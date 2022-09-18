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

const int N = 10000005;
#define pb push_back

void work(){
    // 
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(auto &x : arr) cin >> x;
    // int gcd = arr[0];
    // for(int i = 1;i < arr.size();i++){
    //     gcd = __gcd(gcd, arr[i]);
    // }
    // // for(int i = 0;)
    // sort(arr.begin(), arr.end());
    // int l = -1, r = arr.size();
    // while(r > l + 1){
    //     int mid = (l + (r - l)/2);
    //     if(arr[mid] >= gcd){
    //         r = mid;
    //     }
    //     else l = mid;
    // }
    // if(r < arr.size() && arr[r] == gcd){
    //     cout << arr[r] << endl;
    // }
    // else{
    //     cout << "-1" << endl;
    // }

    // Editorial - answer
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    bool flag = true;
    for(int i = 1;i < arr.size();i++){
        if(arr[i] % arr[0] != 0){
            flag = false;
            break;
        }
    }
    if(flag) cout << arr[0] << endl;
    else cout << "-1" << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


