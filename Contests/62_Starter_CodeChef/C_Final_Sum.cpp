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
    // c) Final Sum
    int n, q;
    cin >> n >> q;
    ll sum = 0;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        sum += num;
    }
    while(q--){
        int start, end;
        cin >> start >> end;
        if((end - start + 1) % 2 == 0){
            continue;
        }
        else sum += 1;
    }
    cout << sum << endl;

    // Editorial.

    // Same Ideology.
    // Time Complexity : O(N + Q).
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


