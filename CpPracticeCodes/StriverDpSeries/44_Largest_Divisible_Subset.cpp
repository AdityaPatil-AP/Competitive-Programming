#include <bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int lastIndex = 0;
    vector<int> hash(n, 0), dp(n, 1);
    int maxi = 1;
    for(int i = 1;i < n;i++){
        hash[i] = i;
        for(int j = 0;j < i;j++){
            if(arr[i]%arr[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}