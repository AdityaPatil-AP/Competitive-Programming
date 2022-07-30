#include <bits/stdc++.h>
using namespace std;

class Solution {
    void helper( vector<int> &nums, vector<int> &ds,vector<bool> &freq, vector<vector<int>> &ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(freq[i] == false){
                ds.push_back(nums[i]);
                freq[i] = true;
                helper(nums, ds, freq, ans);
                freq[i] = false;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);
        helper(nums, ds,freq, ans);
        return ans;
    }
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return 0;
}