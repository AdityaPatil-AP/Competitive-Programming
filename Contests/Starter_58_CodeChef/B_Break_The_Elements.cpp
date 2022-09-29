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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto &x : arr) cin >> x;
    int oddParitySteps = 0;
    int oddPresent = 0;
    for(int i = 0;i < n;i++){
        int temp = arr[i];
        int factor = 0;
        if(arr[i] % 2== 1){
            oddPresent++;
        }
        else{
            oddParitySteps++;
        }
    }
    if(oddPresent) cout << oddParitySteps << endl;
    else cout << "0" << endl;
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


