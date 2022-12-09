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
    // ll n;
    // cin >> n;
    // vector<ll> arr(n, 0);
    // for(auto &x : arr) cin >> x;
    // map<ll, ll> mp;
    // // if(n == 1){
    // //     cout << arr[0] << endl;
    // //     return;
    // // }
    // for(int i = 0;i < n;i++){
    //     mp[arr[i]]++;
    // }for(auto x : mp){
    //     if(x.second >= (((n + 1)/2) + 1)){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
    // if(n <= 2){
    //     for(int i = 0;i < n;i++){
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    //     return;
    // }
    
    // sort(arr.begin(), arr.end());
    // bool start = false;
    // if(arr.size() % 2 == 1){
    //     int m = arr.size()/2;
    //     int count1 = count(arr.begin(), arr.end(), arr[m]);
    //     if(count1 == ((arr.size() + 1)/2)){
    //         if(arr[0] == arr[m]){
    //             start = true;
    //         }
    //     }
    // }
    // int i = 0, j = arr.size() - 1;
    // while(i <= j){
    //     if(i == j){
    //         cout << arr[i] << " ";
    //         break;
    //     }
    //     if(start)
    //     {
    //         cout << arr[i] << " ";
    //         cout << arr[j] << " ";
    //     }
    //     else{
    //         cout << arr[j] << " ";
    //         cout << arr[i] << " ";
    //     }
    //     i++, j--;
    // }
    // cout << endl;
    // return;

    // Editorial Answer.
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    if(n <= 2){
        for(int i = 0;i < n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    // Now based on the case analysis we require to make 
    // two configurations.
    // Now, no two adjacent elements must be equal.
    // x x y1, y1 x x -> may be not increasing or not decreasing. which then doesn't make it interesting.
    // Therefore, we have to make sure no two similar elements are adjacent to one another.
    // We can make a sorted subarray of size less than 2.
    // for n <= 2 ans is always there.
    // So the possible configuration can be, 
    // a1 < a2 > a3 < a4 > a5 and so on.. 
    // This is zig zag configuration.
    // What we can do to achieve this, simple.
    // First sort the array.
    // for  1 <= k <= ceil((double)n/2), A(2k - 1) = S(k).
    // for ceil((double)n/2) + 1 <= k <= n, A(2 * m) = S(k), 
    vector<ll> firstconfig(n, 0);
    int m = 0;
    for(int i = 0;i < n;i+=2){
        firstconfig[i] = arr[m++];
    }
    for(int i = 1;i < n;i+=2){
        firstconfig[i] = arr[m++];
    }
    bool check = true;
    for(int i = 1;i < n;i+=2){
        if((firstconfig[i] > firstconfig[i - 1]) && (i + 1 < n && (firstconfig[i] > firstconfig[i + 1]))){
            continue;
        }
        else if((i + 1) >= n && (firstconfig[i] > firstconfig[i - 1])){
            continue;
        }
        else {
            check = false; 
        }
    }
    // New config check
    // cout << "Firstconfig : " << endl;
    // for(int i = 0;i < n;i++){
    //     cout << firstconfig[i] << " ";
    // }
    // cout << endl;
    if(check){
        for(int i = 0;i < n;i++){
            cout << firstconfig[i] << " ";
        }
        cout << endl;
        return;
    }
    check = true;
    sort(arr.begin(), arr.end(), greater<int>());
    // a1 > a2 < a3 > a4 < a5 > a6 < a7 > a8.
    vector<ll> secondconfig(n, 0);
    m = 0;
    for(int i = 0;i < n;i+=2){
        secondconfig[i] = arr[m++];
    }
    for(int i = 1;i < n;i+=2){
        secondconfig[i] = arr[m++];
    }
    for(int i = 1;i < n;i+=2){
        if((secondconfig[i] < secondconfig[i - 1]) && (i + 1 < n && (secondconfig[i] < secondconfig[i + 1]))){
            continue;
        }
        else if((i + 1) >= n && (secondconfig[i] < secondconfig[i - 1])){
            continue;
        }
        else {
            // cout  << "Hello" << endl;
            check = false; 
        }
    }
    // New config check
    // cout << "SecondConfig : " << endl;
    // for(int i = 0;i < n;i++){
    //     cout << secondconfig[i] << " ";
    // }
    if(check){
        for(int i = 0;i < n;i++){
            cout << secondconfig[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << "-1" << endl;
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
