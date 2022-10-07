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

// kadane's algorithm - A subarray can be empty as well
// It's size is always zero.
// Lower bound is 0 and answer is always greater than that.
// Use functions when answer is becoming repititive. 
// Using insert and erase to add or delete elements at the beginning 
// or end of the array.
// Do binary String wale questions ..
// Permutations wale questions.
ll maximumSumSubarray(vector<ll> &arr){
    int n = arr.size();
    ll tot_sum = INT_MIN, sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        if(sum > tot_sum) 
            tot_sum = sum;
        if(sum < 0)
            sum = 0;
    }
    return tot_sum;
}

void work(){
    // My Try :
    // Maximum Subarray
    int n;
    cin >> n;
    vector<ll> arr1(n, 0);
    for(auto &x : arr1) cin >> x;
    int m;
    cin >> m;
    vector<ll> arr2(m, 0);
    for(auto &x : arr2) cin >> x;
    int sum = 0;
    // Traverse in the second array and find the positive integers
    for(int i = 0;i < m;i++){
        if(arr2[i] > 0){
            sum += arr2[i];
        }
    }
    arr1.insert(arr1.begin(), sum);
    ll maxx = maximumSumSubarray(arr1);
    arr1.erase(arr1.begin(), arr1.begin() + 1);
    arr1.insert(arr1.begin() + n, sum);
    maxx = max(maxx, maximumSumSubarray(arr1));
    cout << maxx << endl;
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


