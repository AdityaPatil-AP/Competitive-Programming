#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int N = 1000000;
#define pb push_back

void work(){
    // 
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    int mini = *min_element(arr.begin(), arr.end());
    for(auto &x  : arr){
        x -= mini;
    }
    int gcd = 0;
    for(int i = 0;i < n;i++){
        if(gcd == 0 && arr[i] > 0) gcd = arr[i]; 
        else if(arr[i] > 0){
            gcd = __gcd(arr[i], gcd);
        }
    }
    if(gcd == 0) cout << "-1" << endl;
    else cout << gcd << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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


