#include <iostream>
using namespace std;
// Using or

bool subsetSum(int *val, int n, int sum){
    bool **dp = new bool*[2];
    for(int i = 0; i <= 1;i++){
        dp[i] = new bool[sum + 1];
    }

    for(int i = 1; i <= sum;i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;

    int flag = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= sum;j++){
            dp[flag][j] = dp[flag ^ 1][j];
            if(val[i - 1] <= j){
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - val[i - 1]];
            }
        }
        flag = flag ^ 1;
    }
    bool ans = dp[flag ^ 1][sum];
    for(int i = 0;i <= n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int val[] = {1, 3, 5, 7, 9};
    int sum = 15;

    cout << subsetSum(val, 5, sum);
    // cout << false;
    return 0;
}