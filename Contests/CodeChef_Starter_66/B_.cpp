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
    // Good Binary Strings.
    string s;
    cin >> s;
    ll n = s.size();
    ll count10 = 0;
    ll count01 = 0;
    for(int i = 0;i < n;i++){
        if(i > 0 && s[i] == '0' && s[i - 1] == '1'){
            count10++;
        }
        else if(i > 0 && s[i] == '1' && s[i - 1] == '0'){
            count01++;
        }
    }
    ll ans = 0;
    for(int i = 1;i < n - 1;i++){
        ll ncount01 = count01, ncount10 = count10;
        if(s[i] == '0'){
            if(s[i - 1] == '1'){
                ncount10--;
            }
            if(s[i + 1] == '1'){
                ncount01--;
            }
            if(s[i - 1] == '0'){
                ncount01++;
            }
            if(s[i + 1] == '0'){
                ncount10++;
            }
            if(ncount01 == ncount10){
                ans++;
            }
        }
        if(s[i] == '1'){
            if(s[i - 1] == '0'){
                ncount01--;
            }
            if(s[i + 1] == '0'){
                ncount10--;
            }
            if(s[i - 1] == '1'){
                ncount10++;
            }
            if(s[i + 1] == '1'){
                ncount01++;
            }
            if(ncount01 == ncount10){
                ans++;
            }
        }
    }
    if(s[0] == '0'){
        ll ncount10 = count10, ncount01 = count01;
        if(s[1] == '1'){
            ncount01--;
        }
        if(s[1] == '0'){
            ncount10++;
        }
        if(ncount01 == ncount10){
            ans++;
        }
    }
    if(s[0] == '1'){
        ll ncount10 = count10, ncount01 = count01;
        if(s[1] == '0'){
            ncount10--;
        }
        if(s[1] == '1'){
            ncount01++;
        }
        if(ncount01 == ncount10){
            ans++;
        }
    }
    if(s[n - 1] == '0'){
        ll ncount10 = count10, ncount01 = count01;
        if(s[n - 2] == '1'){
            ncount10--;
        }
        if(s[n - 2] == '0'){
            ncount01++;
        }
        if(ncount01 == ncount10){
            ans++;
        }
    }
    if(s[n - 1] == '1'){
        ll ncount10 = count10, ncount01 = count01;
        if(s[n - 2] == '0'){
            ncount01--;
        }
        if(s[n - 2] == '1'){
            ncount10++;
        }
        if(ncount01 == ncount10){
            ans++;
        }
    }
    cout << ans << endl;
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
