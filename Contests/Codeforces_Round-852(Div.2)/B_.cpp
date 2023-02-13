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
    // My Try : Correct
    ll maxi, mini;
    cin >> maxi >> mini;

    cout << 2 * abs(maxi - mini) << endl;
    if(maxi == 0){
          for(int i = maxi;i >= mini;i--){
            cout << i << " ";
          }
          for(int i = mini + 1;i < maxi;i++){
            cout << i << " ";
          }
          cout << endl;
    }
    if(mini == 0){
        for(int i = 0;i <= maxi;i++){
            cout << i << " ";
          }
          for(int i = maxi - 1;i >= mini + 1;i--){
            cout << i << " ";
          }
          cout << endl;
    }
    if(mini < 0 && maxi > 0){
        for(int i = 0;i <= maxi;i++){
            cout << i << " ";
        }
        for(int i = maxi - 1;i >= mini;i--){
            cout << i << " ";
        }
        for(int i = mini + 1;i <= -1;i++){
            cout << i << " ";
        }
        cout << endl;
    }
    if(mini > 0){
        for(int i = mini;i <= maxi;i++){
            cout << i << " ";
        }
        for(int i = maxi - 1;i >= mini + 1;i--){
            cout << i << " ";
        }
        cout << endl;
    }
    if(maxi < 0){
        for(int i = maxi;i >= mini;i--){
            cout << i << " ";
        }
        for(int i = mini + 1;i <= maxi - 1;i++){
            cout << i << " ";
        }
        cout << endl;
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

