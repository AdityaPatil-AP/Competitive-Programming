#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
   // K Flip
    // int n, k;
    // cin >> n >> k;
    // string bs;
    // cin >> bs;
    // int use = n - k + 1;
    // for(int i = 0;i <= n - k;i++){
    //     if(bs[i] == '1' && use > 0){
    //         for(int j = 0;j < k;j++){
    //             if(bs[i + j] == '1'){
    //                 bs[i + j] = '0';
    //             }
    //             else{
    //                 bs[i + j] = '1';
    //             }
    //         }
    //         use--;
    //     }
    //     if(use <= 0){
    //         break;
    //     }
    // }
    // cout << bs << endl;

    // Editor's Solution
    // int n, k;
    // cin >> n >> k;
    // string s;
    // cin >> s;

    // Rather than storing as a binary string let's store it as
    // a vector of int
    // vector<int> v(n, 0);
    // for(int i = 0;i < n;i++){
    //     v[i] = s[i] - '0';
    // }

    // queue<int> q;
    // for(int i = 0;i < (n - k + 1);i++){
    //     while(q.size() > 0 && q.front() < (i - (k - 1))){
    //         q.pop();
    //     }
    //     v[i] = (v[i] + q.size()) % 2;
    //     if(v[i] == 0) continue;
    //     v[i] = (v[i] + 1) % 2;
    //     q.push(i);
    // }
    // for(int i = n - k + 1;i < n;i++){
    //     while(q.size() > 0 && q.front() < (i - (k - 1))){
    //         q.pop();
    //     }
    //     v[i] = (v[i] + q.size()) % 2;
    // }
    // string ans(n, '0');
    // for(int i = 0;i < n;i++){
    //     ans[i] = ('0' + v[i]);
    // }
    // cout << ans << endl;

    // Editorial Utkarsh Ans
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt[n + 1] = {0};
    int good[n + 1] = {0};
    for(int i = 0;i < n - k + 1;i++){
        if(i == 0){
            cnt[i] = 0;
        }
        else if(i < k)
            cnt[i] = cnt[i - 1];
        else
            cnt[i] = cnt[i - 1] - good[i - k];
        int tmp = cnt[i];
        tmp %= 2;
        if(tmp == 1)
            s[i] = '0' + '1' - s[i];
        if(s[i] == '1'){
            good[i] = 1;
            cnt[i]++;
            s[i] = '0';
        }
    }
    for(int i = n - k + 1;i < n;i++){
        if(i == 0){
            cnt[i] = 0;
        }
        else if(i < k)
            cnt[i] = cnt[i - 1];
        else 
            cnt[i] = cnt[i - 1] - good[i - k];
        int tmp = cnt[i];
        tmp%= 2;
        if(tmp == 1){
            s[i] = '0' + '1' - s[i];
        }
    }
    cout << s << "\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


