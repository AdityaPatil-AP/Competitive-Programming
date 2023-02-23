#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
#include <numeric>
// #include <boost/math/common_factor.hpp>
using namespace std;
// using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

ll lcm(ll a, ll b){
    ll g = __gcd(a, b);
    return ((a * b)/g);
}

void work(){

    // Editorial

    ll n;
    cin >> n;
    vector<ll> a(n + 2, 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    vector<ll> b(n + 2);
    for(int i = 1;i <= n + 1;i++){
        b[i] = lcm(a[i], a[i - 1]);
    }

    for(int i = 1;i <= n;i++){
        if(__gcd(b[i], b[i + 1]) != a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    // My Try : 
    // ll n;
    // cin >> n; 
    // vector<ll> arr(n, 0);

    // for(auto &x : arr) cin >> x;
    // vector<int> ans;
    // ans.push_back(arr[0]);
    // // If yes or no hai toh.
    // // If the array is either only decreasing or only increasing or constant
    // // then we get answer for sure.
    // // But is a containing either a valley or a peak, then there is no answer.

    // bool isIncreasing = true;
    // for(int i = 1;i < n - 1;i++){
    //     if(arr[i - 1] <= arr[i] && arr[i] <= arr[i + 1]) continue;
    //     else{
    //         isIncreasing = false;
    //         break;
    //     }
    // }

    // bool isDecreasing = true;
    // for(int i = 1;i < n - 1;i++){
    //     if(arr[i] <= arr[i - 1] && arr[i] >= arr[i + 1]) continue;
    //     else{
    //         isDecreasing = false;
    //         break;
    //     }
    // }

    // if(isIncreasing || isDecreasing){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }
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

