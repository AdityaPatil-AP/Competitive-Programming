#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Correct Answer
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // map<int, int> mp;
    // for(int i = 0;i < n;i++){
    //     mp[arr[i]]++;
    // } 
    // vector<int> freq;
    // for(auto it:mp){
    //     freq.push_back(it.second);
    // }
    // sort(freq.begin(), freq.end());
    // if(freq.size() == 1){
    //     cout << "YES" << endl;
    // }
    // else if(freq[freq.size() - 1] != freq[freq.size() - 2]){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }

    // tutorial Solution
    int n;
    cin >> n;
    vector<int> a(n, 0);
    unordered_map<int, int> freq;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    int max_freq = 0, max_freq_count = 0;
    for(auto &i : freq){
        if(i.second > max_freq){
            max_freq = i.second;
            max_freq_count = 1;
        }
        else if(max_freq == i.second){
            max_freq_count++;
        }
    }
    if(max_freq_count == 1){
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