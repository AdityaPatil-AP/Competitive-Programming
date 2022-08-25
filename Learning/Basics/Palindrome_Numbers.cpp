#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool f(int n){
    int j = -1, i = 0;
    vector<int> temp;
    while(n){
        int k = n%10;
        temp.push_back(k);
        n = n/10;
        j++;
    }
    while(i < j){
        if(temp[i] != temp[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void work(){
    // Palindrome Numbers.
    // leetcode
    int n;
    cin >> n;
    bool ans = f(n);
    cout << ans << endl;
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


// Leetcode Submission
class Solution {
public:
    bool f(int n){
        int j = -1, i = 0;
        vector<int> temp;
        while(n){
            int k = n%10;
            temp.push_back(k);
            n = n/10;
            j++;
        }
        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome(int x) {
        // if(x < 0){
        //     return false;
        // }
        // return f(x);
        string s= to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t){
            return true;
        }
        return false;
    }
};