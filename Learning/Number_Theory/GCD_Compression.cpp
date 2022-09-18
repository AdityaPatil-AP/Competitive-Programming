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
    // GCD Compression
    int n;
    cin >> n;
    vector<int> arr(2 * n , 0);
    for(int i = 0;i < 2 * n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int index = 0;
    for(int i = 0;i < 3;i++){
        bool flag = true;
        for(int j = 0;j < 2 * n;j++){
            if(arr[j] % arr[i] == 0) continue;
            else {flag = false; break;}
        }
        if(flag == true) index = i;
    }
    // cout << index << endl;
    if(index >= 1){
        arr[index - 1] = 0;
        arr[index + 1] = 0;
    }
    else{
        arr[index + 1] = 0;
        arr[index + 2] = 0;
    }
    int pairi = 0;
    for(int i = 0;i < 2 * n;i++){
        if(arr[i] != 0){
            cout << arr[i] << " ";
            pairi++;
        }
        if(pairi == 2){
            cout << endl;
            pairi = 0;
        }
        // cout << arr[i] << " ";
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
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


