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

int n, k;
vector<int> arr;
bool good(long double x){
    int cuts = 0;
    for(int i = 0;i < n;i++){
        cuts += floor(arr[i]/x);
    } 
    return (cuts >= k);
}

void work(){
    // Ropes
    cin >> n >> k;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
    cout << setprecision(20);
    long double l = 0, r = 1e8;
    for(int i = 0;i < 100;i++){
        long double mid = (l + r)/2;
        if(good(mid)){
            l = mid;
        }
        else r = mid;
        // cout << i << " " << l << " " << r << endl;
    }
    cout << l <<  endl;
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


