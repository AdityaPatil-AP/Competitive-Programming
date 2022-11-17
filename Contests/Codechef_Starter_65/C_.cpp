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
    // Binod
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n, 0);
    vector<vector<int>> helper(n, vector<int>(60, 0));
    for(int i = 0;i < arr.size();i++){
        ll num;
        cin >> num;
        int k = 0;
        while(num != 0){
            ll m = num % 2;
            if(m == 1){
                helper[i][k]++;
            }
            num = num/2;
            k++;
        }
    }
    
    for(int k = 0;k < 60;k++){
        ll sum = 0;
        for(int i = 0;i < n;i++){
            sum += helper[i][k];
            helper[i][k] = sum;
        }
    }

    // for(int i = 0;i < n;i++){
    //     for(int k = 0;k < 5;k++){
    //         cout << helper[i][k] << " ";
    //     }
    //     cout << endl;
    // }
    // cout  << endl;
    while(q--){
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll numOnesPart1 = 0, numOnesPart2 = 0, numZeroPart1 = 0, numZeroPart2 = 0;
        if(l1 == 1) numOnesPart1 = helper[r1 - 1][k];
        else numOnesPart1 = helper[r1 - 1][k] - helper[l1 - 2][k];
        numOnesPart2 = helper[r2 - 1][k] - helper[l2 - 2][k];
        ll ans = (numOnesPart1 * (r2 - l2 + 1 - numOnesPart2));
        ans += (r1 - l1 + 1 - numOnesPart1) * (numOnesPart2);
        cout << ans << endl;
    }
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
