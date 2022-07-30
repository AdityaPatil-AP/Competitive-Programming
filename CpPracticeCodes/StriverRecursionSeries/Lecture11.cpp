#include <bits/stdc++.h>
using namespace std;

// What are Subsequences?

// We can answer that by understanding the difference between Subarray, Subsequence and Subset

// A subarray is a contiguous part of array and maintains relative ordering of elements. For an array/string of size n, there are n*(n+1)/2 non-empty subarrays/substrings.

// A subsequence maintain relative ordering of elements but may or may not be a contiguous part of an array. For a sequence of size n, we can have 2^n-1 non-empty sub-sequences in total.

// A subset does not maintain relative ordering of elements and is neither a contiguous part of an array. For a set of size n, we can have (2^n) sub-sets in total.

// Let us understand it with an example.

// Consider an array:

// array = [1,2,3,4]

// Subarray : [1,2],[1,2,3] - is continous and maintains relative order of elements

// Subsequence: [1,2,4] - is not continous but maintains relative order of elements

// Subset: [1,3,2] - is not continous and does not maintain relative order of elements

// Some interesting observations :

// Every Subarray is a Subsequence.
// Every Subsequence is a Subset.


class Solution {
    void helper(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans){
        ans.push_back(subset);
        for(int i = index;i < nums.size();i++){
            if(i > index && nums[i] == nums[i - 1]){
                continue;               
            }
            subset.push_back(nums[i]);
            helper(i + 1, nums, subset, ans);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        helper(0, nums, subset, ans);
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