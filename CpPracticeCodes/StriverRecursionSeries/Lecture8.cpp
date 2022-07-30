#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(int index, vector<int>& candidates, int target,vector<int> sequence, vector<vector<int>> &ans){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(sequence);
            }
            return;
        }
            
        // take
        if(target >= candidates[index]){
            target -= candidates[index];
            sequence.push_back(candidates[index]);
            helper(index, candidates, target, sequence, ans);
            target += candidates[index];
            sequence.pop_back();
        }
        
        // not take
        helper(index + 1, candidates, target, sequence, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sequence;
        helper(0, candidates, target,sequence, ans);
        return ans;
    }
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cout << "hello" << endl;
	cout << "hello " << endl;
	return 0;
}