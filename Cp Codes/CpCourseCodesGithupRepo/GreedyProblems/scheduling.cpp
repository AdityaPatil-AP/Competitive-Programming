#include <iostream>
#include <algorithm>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool compare(Job a, Job b){
    return a.finish < b.finish;
}

int fMProfit(Job arr[], int n){
    sort(arr, arr + n, compare);
    int *dp = new int[n];
    dp[0] = arr[0].profit;
    for(int i = 1;i < n;i++){
        int including = arr[i].profit;
        int lNConflict = -1;
        for(int j = i - 1;j >= 0;j--){
            if(arr[j].finish <= arr[i].start){
                lNConflict = j;
                break;
            }
        }
        if(lNConflict != -1){
            including += dp[lNConflict];
        }
        dp[i] = max(dp[i - 1], including);
    }
    int result = dp[n - 1];
    delete [] dp;
    return result;
}

int main(){
    Job arr[] = {{2, 5, 50}, {1, 2, 20}, {6, 9, 70}, {2, 50, 400}};
    cout << "Maximum Profit is : " << fMProfit(arr, 4) << endl;
    return 0;
}