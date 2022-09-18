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
    int n;
    cin >> n;
    string t;
    cin >> t;
    string code = "";
    for(int i = 0;i < n;i++){
        int val;
        if((i + 1 < n) && ((t[i] - '0') * 10 + (t[i + 1] - '0')) > 26) {
            code += ('a' + (t[i] - '0') - 1);
        }
        else if((i + 3 < n) && ((t[i] - '0') * 10 + (t[i + 1] - '0')) <= 26 && t[i + 2] == '0'){

        }
        else if((i + 2 < n) && ((t[i] - '0') * 10 + (t[i + 1] - '0')) <= 26 && t[i + 2] == '0'){
            val=((t[i] - '0') * 10 + (t[i + 1] - '0'));
            code += ('a' + val - 1);
            i += 2;
        }
        else{
            code += ('a' + (t[i] - '0') - 1);
        }
    }
    cout << code << endl;
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


