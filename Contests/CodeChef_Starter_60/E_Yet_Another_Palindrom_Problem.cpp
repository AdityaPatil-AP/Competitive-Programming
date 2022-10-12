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
    // Yet another Palindrome Problem
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int &x : arr) cin >> x;
    int i,j;
    if(n % 2 == 0) i = n/2 - 1, j = n/2;
    else i = n/2 - 1, j = n/2 + 1;
    int change = 0;
    bool flag = true;
    while(i >= 0 && j < n){
        if((arr[i] + change) == arr[j]){

        }
        else if((arr[i] + change) < arr[j]){
            arr[i] += change;
            change += (arr[j] - arr[i]);
        }
        else{
            flag = false;
        }
        i--, j++;
    }
    if(flag) cout << change << endl;
    else cout << "-1" << endl;
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


