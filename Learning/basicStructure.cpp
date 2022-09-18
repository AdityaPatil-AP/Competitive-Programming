#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int N = 1000000;
#define pb push_back

bool comp(vector<int> &a, vector<int> &b){
    if(a[0] <= b[0]){
        if(a[0] == b[0] && b[1] < a[1]){
            return false;
        }
        return true;
    }
    return false;
}

int f(int ind, int prev, int k, vector<int> &nums, vector<int> &dp){
        // Base Case.
        if(ind == 0){
            if(prev - arr[0] <= k){
                return 1;
            }
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        // explorations
        int skip = f(ind - 1, k, nums,dp);
        
        int take = INT_MAX;
        if(prev - arr[ind] <=  k){
            prev = arr[ind];
            take = 1 + f(ind - 1, prev, k, nums, dp);
        }
        return min(take, skip);
    }

void work(){
    // 2nd question
    // string s = "abacaba";
    // set<char> st;
    // int cnt = 0;
    // for(int i = 0;i < s.size();i++){
    //     if(st.find(s[i]) == st.end() || st.size() == 0){
    //         st.insert(s[i]);
    //     }
    //     else{ 
    //         cnt++;
    //         st.erase(st.begin(), st.end());
    //         i--;
    //     }
    // }
    // if(st.size() != 0){
    //     cnt++;
    // }
    // cout << cnt << endl;

    // 3rd question
    // vector<vector<int>> intervals = {{5,10}, {6,8}, {1,5}, {2,3}, {1,10}};
    // sort(intervals.begin(), intervals.end(), comp);
    // for(int i = 0;i < intervals.size();i++){
    //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
    // }
    // // cout << intervals.size() << endl;
    // vector<int> ending;
    // ending.push_back(intervals[0][1]);
    // int minEnding = intervals[0][1];
    // for(int i = 1;i < intervals.size();i++){
    //     bool found = false;
    //     if(intervals[i][0] < minEnding){
    //         if(intervals[i][1] < minEnding){
    //             minEnding = intervals[i][1];
    //         }
    //         ending.push_back(intervals[i][1]);
    //         continue;
    //     }
    //     for(int j = 0;j < ending.size();j++){
    //         if(intervals[i][0] > ending[j]){
    //             found = true;
    //             ending[j] = intervals[i][1];
    //             if(minEnding > ending[j]){
    //                 minEnding = ending[j];
    //             }
    //             break;
    //         }
    //     }
    //     if(!found) {
    //         ending.push_back(intervals[i][1]);
    //     }
    // }
    // cout << ending.size() << endl;


}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


