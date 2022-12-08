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
    // Boring String
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> freq(26);
    if(n <= 1){
        cout << 0 << endl;
        return;
    }
    ll count = 1;
    for(int i = 0;i < n - 1;i++){
        if(s[i] == s[i + 1]){
            count++;
        }
        else{
            int index = s[i] - 'a';
            freq[index].push_back(count);
            count = 1;
        }
    }
    if(s[n - 1] == s[n - 2]){
        int index = s[n - 1] - 'a';
        freq[index].push_back(count);
    }
    else{
        int index = s[n - 1] - 'a';
        freq[index].push_back(count);
    }
    ll ans = 0;
    for(int i = 0;i < 26;i++){
        vector<ll> m = freq[i];
        ll maxnow = 0;
        ll maxpairnow = 0;
        int j = 0;
        while(j < m.size()){
            maxnow = max(maxnow, m[j]);
            ll curr = m[j];
            m.erase(m.begin() + j);
            if(find(m.begin(), m.end(), curr) != m.end()){
                maxpairnow = max(maxpairnow, curr);
            }
        }
        ans = max(ans, max(maxpairnow, maxnow - 1));
        // cout  << endl;
    }
    cout << ans <<endl;
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
