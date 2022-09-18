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

void work(){
    // Fast Search
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    // for(auto x : arr) cout << x;

    sort(arr.begin(), arr.end());
    int k;
    cin >> k;
    while(k--){
        int smallest, largest;
        cin >> smallest >> largest;
        // to find the index such that a[index] >= smallest
        int l = -1, r = n;

        while(r > l + 1){
            int mid = (l + (r - l)/2);
            if(arr[mid] >= smallest){
                r = mid;
                // cout << r <<endl;

            }
            else{
                l = mid;
            }
        }
        // if(r == n) r = n - 1;
        int i = r;
        // cout << i <<endl;
        // to find the index such that arr[index] <= largest
        l = -1, r = n;
        while(r > l + 1){
            int mid = (l + (r - l)/2);
            if(arr[mid] <= largest){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        // if(l == -1) l = 0;
        int j = l;
        // cout << j <<endl;
        cout << abs(j - i + 1) << " ";
    }
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


