#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // F. Array Equality
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int maxi = INT_MIN;
    for(auto i : mp){
        maxi = max(maxi, i.second);
    }
    if(maxi <= ceil((double)n/2)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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