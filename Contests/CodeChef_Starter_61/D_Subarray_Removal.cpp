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

void work(){
    // My Try :
    // D) Subarray Removal
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    // int i = 0;
    // int ans = 0;
    // while(i < n){
    //     if((i + 1 < n) && ((arr[i] == 0 && arr[i + 1] == 1) || (arr[i] == 1 && arr[i + 1] == 0))){
    //         ans++;
    //         i += 2;
    //     }
    //     else if(i + 2 < n && (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 1)){
    //         ans++;
    //         i += 3;
    //     }
    //     else i++;
    // }

    // map<int, int> mp;
    // int ans = 0;
    // for(int i = 0;i < n;i++){
    //     mp[arr[i]]++;
    //     // cout << mp[0] << " " << mp[1] << endl;
    //     if(mp[0] == 1 && mp[1] == 1){
    //         ans++;
    //         mp[0] = 0;
    //         mp[1] = 0;
    //     }
    //     else if(mp[0] == 0 && mp[1] == 3){
    //         ans++;
    //         mp[1] = 0;
    //     }
    // }

    // int ans = 0;
    // int i, j;
    // if(n % 2) i = n/2 - 1, j = n/2;
    // else i = n/2 - 1, j = n/2;
    // while(i >= 0 && j <= n - 1){
    //     int curr = (arr[i] ^ arr[j]);
    //     if(curr == 1){
    //         ans++;
    //         i--, j++;
    //     }
    //     else{
    //         if(j + 1 <= n - 1 && curr^arr[j+1] == 1) j++;
    //         else if(i - 1 >= 0 && curr ^ arr[i-1]==1) i--; 
    //         else i--, j++;
    //     }
    // }

    int ans = 0;
    int cnt0 = count(arr.begin(), arr.end(), 0);
    int cnt1 = count(arr.begin(), arr.end(), 1);
    int take = min(cnt1, cnt0);
    cnt1 -= take;
    ans += take;
    if(cnt1 > 0) ans += cnt1/3; 
    cout << ans << endl;
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


