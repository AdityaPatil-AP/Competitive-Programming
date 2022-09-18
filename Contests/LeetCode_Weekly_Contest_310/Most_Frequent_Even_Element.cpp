class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }
        int ans = -1;
        int freq = 0;
        for(auto x : mp){
            if(x.second > freq || (ans > x.first && x.second == freq)){
                ans = x.first; 
                freq = x.second;
            }
        }
        return ans;
    }
};