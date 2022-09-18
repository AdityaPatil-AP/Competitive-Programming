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

int binarySearch(vector<int> arr, int x){
    
    return -1;
}

void work(){
    // Binary Search
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    while(k--){
        int to_find;
        cin >> to_find;
        bool ok = false;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + (high - low)/2);
            if(arr[mid] == to_find){
                ok = true;
                break;
            }
            else if(arr[mid] > to_find){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
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


