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
    // Interesting arrays.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    map<ll, ll> mp;
    // if(n == 1){
    //     cout << arr[0] << endl;
    //     return;
    // }
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;
    }
    for(auto x : mp){
        if(x.second >= (((n + 1)/2) + 1)){
            cout << -1 << endl;
            return;
        }
    }
    sort(arr.begin(), arr.end());
    bool start = false;
    if(arr.size() % 2 == 1){
        int m = arr.size()/2;
        int count1 = count(arr.begin(), arr.end(), arr[m]);
        if(count1 == ((arr.size() + 1)/2)){
            if(arr[0] == arr[m]){
                start = true;
            }
        }
    }
    int i = 0, j = arr.size() - 1;
    while(i <= j){
        if(i == j){
            cout << arr[i] << " ";
            break;
        }
        if(start)
        {
            cout << arr[i] << " ";
            cout << arr[j] << " ";
        }
        else{
            cout << arr[j] << " ";
            cout << arr[i] << " ";
        }
        i++, j--;
    }
    cout << endl;
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
