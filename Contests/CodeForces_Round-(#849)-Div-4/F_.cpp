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

ll update(ll num){
    ll sum = 0;
    while(num > 0){
        ll temp = num % 10;
        sum += temp;
        num /= 10;
    }
    return sum;
}

void work(){
    // My Try : 
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;

    // int count = 0;
    // for(int i = 0;i < arr.size();i++){
    //     if(arr[i] >= 10) count++;
    //     arr[i] = count;
    // }

    vector<ll> operations(n, 0);
    vector<ll> OperationsTill(n, 0);
    for(int i = 0;i < n;i++){
        OperationsTill[i] = i;
    }
    while(q--){
        // cout << q << endl;
        ll option;
        cin >> option;
        // Update.
        if(option == 1){
            ll l, r;
            cin >> l >> r;
            l--, r--;
            // tillWhere in '0' based indexing.
            ll tillWhere = OperationsTill[l];
            if(tillWhere >= r) continue;
            ll start = l;
            ll end = l;
            for(int i = (tillWhere);i <= r;i++){
                arr[i] = update(arr[i]);
                operations[i]++;
                if(operations[i] >= 3 || arr[i] <= 9){
                    end++;
                }else{
                    for(int i = start;i < end;i++){
                        OperationsTill[i] = end - 1;
                    }
                    start = end + 1;
                    end = start;
                }
            }

        }
        else{
            ll x;
            cin >> x;
            cout << arr[x - 1] << endl;
        }
    }
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


