#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int N = 1000000;
#define pb push_back

void work(){
    // Or Matrix.
    ll n, m;
    cin >> n >> m;
    vector<bool> rowOne(n, false);
    vector<bool> columnOne(m, false);
    bool onePresent = false;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < m;j++){
            if(s[j] == '1'){
                onePresent = true;
                columnOne[j] = true;
                rowOne[i] = true;
                arr[i][j] = 1;
            }
        }
    }
    // if(!onePresent){
    //     cout << "-1" << endl;
    //     return;
    // }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 1){
                cout << 0 << " ";
            }
            else if(columnOne[j] || rowOne[i]){
                cout << 1 << " ";
            }
            else if(onePresent) cout << 2 << " ";
            else cout << "-1" << endl;
        }
        cout << endl;
    }
    return;
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


