#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int houseRobber(int index, vector<int> &vec, vector<int> &dp){
    // my try
    // if(index == 0){
    //     if(flag == true){
    //         if(vec[index] > vec[vec.size() - 1]){
    //             return vec[index] - vec[vec.size() - 1];
    //         }
    //         else{
    //             return 0;               
    //         }
    //     }
    //     return vec[index];
    // }

    // if(index < 0){
    //     return 0;
    // }

    // if(dp[index] != -1){
    //     return dp[index];
    // }
    // flag = true;
    // int take  = vec[index] + houseRobber(index - 2, vec, dp, flag);
    // flag = false;
    // int nottake = 0 + houseRobber(index - 1, vec, dp, flag); 

    // return dp[index] = max(take, nottake);

    // Striver Solution Same as lecture 5 - just slight change
    // You cannot pick adjacent elements and in this question last and 
    // first are adjacent to one another so what we did was to either exclude first and 
    // calculate the answer or exclude the last one and calculate the answer


    if(index == 0){
        return vec[index];
    }
    if(index < 0){
        return 0;
    }

    if(dp[index] !=  -1){
        return dp[index];
    }
    int take = vec[index] + houseRobber(index - 2, vec, dp);
    int nottake = houseRobber(index - 1, vec, dp);

    return dp[index] = max(take , nottake);
}

void work(){
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(auto &x:vec){
        cin >> x;
    }
    vector<int> dp(n, -1);
    vector<int> temp1, temp2;
    // temp1 stores all the elements except the first
    // temp2 stores all the elements except the last
    for(int i = 0;i < n;i++){
        if(i != 0) temp1.push_back(vec[i]);
        if(i != (n - 1)) temp2.push_back(vec[i]);
    }
    // Recursion and Memoisation
    int ans1 = houseRobber(n - 2, temp1, dp);
    int ans2 = houseRobber(n - 2, temp2, dp);
    cout << max(ans1, ans2) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\StriverDpSeries\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\StriverDpSeries\\output.txt", "w", stdout);
    #endif
    int testcases = 1;
    cin >> testcases;
    for(int i = 0;i < testcases;i++)
        work();
    return 0;
}