#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // My Attempt - correct
    int n;
    cin >> n;
    map<int, int> mp;
    mp[0] = 0;
    mp[1] = 0;
    bool oddP = false;
    for(int i = 0;i < n;i++){
        int m;
        cin >> m;
        if(m % 2 != 0){
            mp[1]++;
        }
        else{
            mp[0]++;
        }
    }
    if((mp[0] != 0 && mp[1] != 0) || (mp[1]%2)){
        oddP = true;
    }
    cout << (oddP ? "YES" : "NO") << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet\\output.txt", "w", stdout);
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


