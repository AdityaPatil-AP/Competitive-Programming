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
    // My try :
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n, -1);

    map<int, int> present;

    // (i + 1) indicates the time gone.
    int delay = 0;
    int changeIndex = n - 1;
    for(int i = 0;i < m;i++){
        int a;
        cin >> a;
        if(present[a] == 1){
            continue;
        }
        present[a] = 1;
        if(changeIndex >= 0) arr[changeIndex--] = i + 1;
    }


    for(auto i : arr){
        cout << i << " ";
    }

    cout << endl;

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

