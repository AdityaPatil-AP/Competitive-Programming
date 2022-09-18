class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] <= b[0]){
            if(a[0] == b[0] && b[1] < a[1]){
                return false;
            }
            return true;
        }
        return false;
    }
    
    int minGroups(vector<vector<int>>& intervals) {
        // My Big try.
        // sort(intervals.begin(), intervals.end(), (compare));
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
        // return ending.size();
        
        // Using the concept of Prefix sum
        int n = intervals.size();
        int arr[1000005] = {0};
        for(int i = 0;i < n;i++){
            arr[intervals[i][0]] += 1;
            arr[intervals[i][1] + 1] += -1;
            
        }
        int maxi = 0;
        for(int i = 1;i < 1000005;i++){
            arr[i] += arr[i - 1];
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};