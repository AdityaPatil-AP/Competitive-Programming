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
    // Confusing Catenations.
    int n;
    cin >> n;
    if(n == 1){
        cout << "-1" << endl;
    }
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    int first = arr[0];
    int i;
    for(i = 1;i < n;i++){
        if(arr[i] > first){
            break;
        }
    }   
    if(i == n){
        cout << "-1" << endl;
    } 
    else{
        cout << i << endl;
        for(int j = 0;j < i;j++){
            cout << arr[j] << " ";
        }
        cout << endl;
        cout << n - i << endl;
        for(int j = i;j < n;j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
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


