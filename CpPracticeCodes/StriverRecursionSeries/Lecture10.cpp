#include <bits/stdc++.h>
using namespace std;

class Solution {
    void helper(int index, vector<int> &candidates, int target, vector<int> &sequence, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(sequence);
            return;
        }
        for(int i = index;i < candidates.size();i++){
            if(candidates[i] > target){
                break;
            }
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            sequence.push_back(candidates[i]);
            helper(i + 1, candidates, target - candidates[i], sequence, ans);
            sequence.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sequence;
        helper(0, candidates, target, sequence, ans);
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