#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
#include <numeric>
// #include <boost/math/common_factor.hpp>
using namespace std;
// using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

ll lcm(ll a, ll b){
    ll g = __gcd(a, b);
    return ((a * b)/g);
}

bool isPalindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]) return false;
        i++, j--;
    }

    return true;
}

void work(){
    // My try :
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(isPalindrome(s)){
        cout << "YES" << endl;
        return;
    }
    int opposite = 0;
    bool isOpposite = false;
    for(int i = 0, j = n - 1;i < n/2;i++, j--){
        if(isOpposite == true && s[i] != s[j]) continue;
        if(s[i] != s[j]){
            opposite++;
            isOpposite = true;
        }
        else isOpposite = false;
    }
    if(opposite <= 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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

