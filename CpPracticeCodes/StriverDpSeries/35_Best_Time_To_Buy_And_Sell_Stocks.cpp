#include <bits/stdc++.h> 
int maximumProfit(vector<int> &values){
    // Write your code here.
    int profit = 0;
    int mini = values[0];
    for(int i = 1;i < values.size();i++){
        int cost = values[i] - mini;
        profit = max(profit, cost);
        mini = min(values[i], mini);
    }
    return profit;
}