#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;
    } 
    vector<int> freq;
    for(auto it:mp){
        freq.push_back(it.second);
    }
    sort(freq.begin(), freq.end());
    if(freq.size() == 1){
        cout << "YES" << endl;
    }
    else if(freq[freq.size() - 1] != freq[freq.size() - 2]){
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
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}