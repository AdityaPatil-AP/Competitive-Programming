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
    // E) Sorted Substrings
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;
    // ll ans = 0;
    // int i = 0;
    // while(i < n){
    // 	while(i < n && s[i] == '0'){
    // 		i++;
    // 	}
    // 	if(i + 1 < n && s[i] == '1' && s[i + 1] == '0'){
    // 		ans++;
    // 	}
    // 	i++;
    // }
    // cout << ans << endl;

    // Editorial
    // convert the binary string into Alternating String First.
    // Delete either the 0's or the 1's and the remaining size of the string is 
    // the answer.
    // or Simple way is to count the number of "10" in the string.
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll pos = 0;
    ll cnt = 0;
    while((pos = s.find("10", pos)) != std::string::npos){
        cnt++;
        pos += 2;
    }
    cout << cnt << endl;
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


