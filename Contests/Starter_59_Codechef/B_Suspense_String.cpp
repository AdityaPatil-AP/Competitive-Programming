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
    // Suspense String
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = n - 1;
    int chance = 0;
    string ans = "";
    while(i <= j){
        if(chance % 2 == 0){
            int start = (s[i] - '0');
            if(start == 0){
                ans = '0' + ans;
                i++;
            }
            else if(start == 1){
                ans = ans + '1';
                i++;
            }
        }
        else if(chance % 2 == 1){
            int end = (s[j] - '0');
            if(end == 1){
                ans = '1' + ans;
                j--;
            }
            else if(end == 0){
                ans = ans + '0';
                j--;
            }
        }
        chance++;
    }
    cout << ans << endl;
    return;
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


