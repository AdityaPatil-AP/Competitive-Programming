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

void work()
{
    // My Try :
    // Nahaane Ja
    ll n, k;
    cin >> n >> k;
    // vector<ll> arr(n, 0);
    // for(auto &x : arr) cin >> x;
    set<int> st;
    if(n == 1) {
        int m;
        cin >> m;
        if(m == k){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        return;
    }
    for(int i = 0;i< n - 1;i++){
        int x;
        cin >> x;
        st.insert(x);
    }
    int m;
    cin >> m;
    if(st.find(k) != st.end()){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt", "r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        work();
    }
    return 0;
}