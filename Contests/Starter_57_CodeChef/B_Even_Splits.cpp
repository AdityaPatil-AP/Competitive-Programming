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

// const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    int n;
    cin>>n;
    string s;
    cin >> s;
    // counting the number of ones
    int countOne = 0;
    // checking if 0 is ahead.
    bool isZeroAhead = false;
    for(int i = 0;i < n;i++){
        if(s[i] == '1'){ 
            countOne++;
        }
        if(i < n - 1 && (s[i] == '0' && s[i + 1] == '1')){
            isZeroAhead = true;
        }
    }
    if(!isZeroAhead){
        cout << s << endl;
        return;
    }
    else{
        string a = "";
        int i;
        for(i = 0;i < n - countOne;i++){
            a += "0";
        }
        for(i = 0;i < countOne;i++){
            a += "1";
        }
        cout << a << endl;
        return;
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


