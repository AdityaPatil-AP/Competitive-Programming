#define ll long long int
class Solution {
public:
    // Iterative Approach for 4Sum.
    // In generalisation for kSum problem, we can have (k - 2 nested loops) and then in sorted array 
    // we implementing the two pointer appraoch.
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i < n - 3;i++){
            /* Conditions for pruning */
            if(target <= 0 && nums[i] > 0) break;
            // if nums[i] has become too large.. no point in continuing
            if((ll)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // if nums[i] is very small that the largest numbers also can't help to reach the sum.
            if((ll)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            // newtarget
            ll newtarget = target - nums[i];
            // skip duplicates.
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1;j < n - 2;j++){
                /* Conditions for pruning */
                // if nums[j] is small that even the largest numbers are not helping to reach the sum.
                if((ll)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                // if nums[j] has become too large, then there is no point in continuing.
                if((ll)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // skip duplicates
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                // newtarget2
                ll newtarget2 = newtarget - nums[j];
                int low = j + 1, high = n - 1;
                while(low < high){
                    ll sum = nums[low] + nums[high];
                    if(sum < newtarget2){
                        low++;
                    }
                    else if(sum > newtarget2){
                        high--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int lownumber = nums[low];
                        while(low < high && nums[low] == lownumber){
                            low++;
                        }
                        int highnumber = nums[high];
                        while(low < high && nums[high] == highnumber){
                            high--;
                        }
                    } 
                }
            }
        }
        return ans;
    }
};