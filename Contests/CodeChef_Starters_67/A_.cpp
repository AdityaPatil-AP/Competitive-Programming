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

void work()
{
    // My Try :
    // Counting Steps.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    bool oddPresent = false;
    ll sum = 0;
    for(int i = 0;i < arr.size();i++){
        if(oddPresent == false && arr[i] % 2 == 1){
            oddPresent = true;
        }
        else sum += arr[i];
    }
    if(oddPresent && sum % 2 == 1){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        work();
    }
    return 0;
}
