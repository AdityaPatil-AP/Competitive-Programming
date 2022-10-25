#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int
#define mod 1000000007

// Using Binet's Formula
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

void work(){
    // My Try
    // Sell all the Cars
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    ll ans = 0;
    for(auto &x : arr) cin >> x;
    // Sorting in decreasing order
    // So that the car with the highest price gives us the maximum 
    // profit.
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0;i < n;i++){
        ans += max(0, arr[i] - i);
    }
    cout << ans % mod << endl;
    return; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


