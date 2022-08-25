int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    long next2 = 0; // if you start on this day and you can sell this stock
    long next1 = 0; // if you start on this day and you can buy this stock
    // Just adding a transaction fee for every stock buy from the market.
    for(int i = n - 1;i >= 0;i--){
        // Buying
        long curr1 = max(-prices[i] + next2, next1);
        // Selling
        long curr2 = max(prices[i] - fee + next1, next2);
        next1 = curr1;
        next2 = curr2;
    }
    return next1;
}
