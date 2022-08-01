#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverDpSeries\\input.txt","r", stdin);
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverDpSeries\\output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int *arr = new int[n + 1];
        bool *friendWS = new bool[n + 1]();
        for(int i = 1;i <= n;i++){
            cin >> arr[i];
        }
        arr[0] = 0;
        unordered_map<int, vector<int>> friends;
        for(int i = 0; i < m;i++){
            int f1, f2;
            cin >> f1 >> f2;
            friends[f1].push_back(f2);
            friends[f2].push_back(f1);
            friendWS[f1] = true;
            friendWS[f2] = true;
        }
        int unhappiness = 0;
        while(m % 2 != 0 && m >= 0){
            int index = 0;
            int minimum = INT_MAX;
            for(int i = 1;i <= n; i++){
                if(friendWS[i] == true && minimum > arr[i]){
                    index = i;
                    minimum = arr[i];
                }
            }
            unhappiness += arr[index];
            // cout << unhappiness << endl;
            m -= (friends[index]).size();
            // if(friends[index].size() == 0)
                friendWS[index] = false;
        }
        cout << unhappiness << endl;
    }


    return 0;
}