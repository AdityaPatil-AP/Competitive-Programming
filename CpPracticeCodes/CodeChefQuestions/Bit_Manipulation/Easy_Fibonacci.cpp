#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int


// Using Binet's Formula
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

void work(){
    // My Try
    // Easy Fibonacci.
    ll n;
    cin >> n;
    // Finding the set bit from MSB side.
    int i = 0;
    while(n > 0){
        n /= 2;
        i += 1;
    }
    i -= 1;
    // fibonacci number to be found.
    ll k = pow(2, i);
    // As Fibonacci series is an exponentially growing series, we have to use 
    // %10 at every step.
    // According to the constraints we have to do it in log2(n) time.(10^18).
    vector<ll> fib(60, 0ll);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2;i < 60;i++){
        fib[i] = (fib[i - 1] + fib[i - 2])%10;
    }
    int ans = fib[(k - 1) % 60];
    cout << ans << endl;
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


