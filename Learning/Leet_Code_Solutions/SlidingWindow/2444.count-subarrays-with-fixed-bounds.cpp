class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // My Answer- Wrong Submission
        // // array + subarray + fixed sliding window question.
        // int i = 0, j = 0; // creation of the window.
        // // mini and maxi will tell the maximum and minimum at the current time.
        // int mini = INT_MAX, maxi = INT_MIN;
        // // will tell me the current elements present in the subarray.
        // map<int, int> mp;
        // // Handled the case when maxi is equal to mini
        // if(minK == maxK){
        //     long long int count = 0;
        //     for(int i= 0;i < nums.size();i++){
        //         if(minK == nums[i]){
        //             count++;
        //         }
        //     }
        //     return (count * (count + 1))/2;
        // }
        // int totCount = 0;
        // int currCount = 0;
        // bool flag = false;
        // while(j < nums.size()){
        //     // calculations.
        //     mp[nums[j]]++;
        //     mini = min(mini, nums[j]);
        //     maxi = max(maxi, nums[j]);
        //     if(mini == minK && maxK == maxi){
        //         currCount++;
        //         j++;
        //     } 
        //     else if(mini != minK || maxi != maxK){
        //         if(currCount >= 1){
        //             totCount += currCount;
        //             while(i < j){
        //                 i++;
        //                 mp[nums[i]]--;
        //                 if(mp[minK] == 0 || mp[maxK] == 0) break;
        //                 currCount--;
        //                 totCount += currCount;
        //             } 
        //             i = j;
        //             currCount = 0;
        //         }
        //         j++;
        //     }
        // }
        // return totCount; 
        
        // Three Pointer Variable Sliding Window..
            long res = 0;
            long jbad = -1, jmin = -1, jmax = -1, n = nums.size();
            for(int i = 0;i < n;i++){
                if(nums[i] < minK || nums[i] > maxK){
                    jbad = i;
                } 
                if(minK == nums[i]) jmin = i;
                if(maxK == nums[i]) jmax = i;
                res += max(0L, min(jmin, jmax) - jbad);
            }
            return res;
    }
};