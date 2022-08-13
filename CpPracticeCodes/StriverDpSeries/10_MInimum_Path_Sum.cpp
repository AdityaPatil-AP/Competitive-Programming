// int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(i == 0 && j == 0){
//         return grid[i][j];
//     }
//     if(i < 0 || j < 0){
//         return 0;
//     }
//     if(i == 0){
//         int sum = 0;
//         for(int m = 0;m <= j;m++){
//             sum += grid[0][m];
//         }
//         return sum;
//     }
//     if(j == 0){
//         int sum = 0;
//         for(int m = 0;m <= i;m++){
//             sum += grid[m][0];
//         }
//         return sum;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int upSum = grid[i][j], leftSum = grid[i][j];
//     if(i > 0)
//         upSum += minSum(i - 1, j, grid, dp);
//     if(j > 0)
//         leftSum += minSum(i, j - 1, grid, dp);
//     return dp[i][j] = min(upSum, leftSum);
// }

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    // Recursion and then after that
    // We encountered many overlapping sub - problems
    // We used memoisation
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return minSum(n - 1, m - 1, grid, dp);
    
    // Tabulation
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, 0));
//     int sum = 0;
//     // We know that in the first column we can only go up 
//     // Therefore we will simply add the grid values we encounter in
//     // our path
//     for(int i = 0;i < n;i++){
//         sum += grid[i][0];
//         dp[i][0] = sum;
//     }
//     // We know that in the first row we can only move left 
//     // Therefore we will simply add the grid values we encounter in
//     // our path
//     sum = 0;
//     for(int i = 0;i < m;i++){
//         sum += grid[0][i];
//         dp[0][i] = sum;
//     }
//     // Minimum path sum of 0,0 would be obviously the grid value itself
//     dp[0][0] = grid[0][0];
//     for(int i = 1;i < n;i++){
//         for(int j = 1;j < m;j++){
//             dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[n - 1][m - 1];
    
    // Space Optimisation;
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    // We know that in the first row we can only move left 
    // Therefore we will simply add the grid values we encounter in
    // our path
    int sum = 0;
    for(int i = 0;i < m;i++){
        sum += grid[0][i];
        prev[i] = sum;
    }
    // Minimum path sum of 0,0 would be obviously the grid value itself
    prev[0] = grid[0][0];
    for(int i = 1;i < n;i++){
        vector<int> cur(m, 0);
        int sum = 0;
        for(int m = 0;m <= i;m++){
            sum += grid[m][0];
        }
        cur[0] = sum;
        for(int j = 1;j < m;j++){
             cur[j] = grid[i][j] + min(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m - 1];
    
}


// Working with Striver and correcting my solution for using smaller length source code

// #include <climits>
// int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(i == 0 && j == 0){
//         return grid[0][0];
//     }
// //     We can never go outside the grid so we return 
// //     as maximum value as possible
//     // As we cannot move in the negative indices they should return
//     // a huge value which can never be achieved within our constraints
//     // that is minimum path sum must be like 10^8 or 10^9 but not
//     // INT_MAX because adding something to it will result in making it 
//     // a negative integer so TAKE CARE OF IT!!!
//     if(i < 0 || j < 0){
//         return 1e8;
//     }
// //     if(i == 0){
// //         int sum = 0;
// //         for(int m = 0;m <= j;m++){
// //             sum += grid[0][m];
// //         }
// //         return sum;
// //     }
// //     if(j == 0){
// //         int sum = 0;
// //         for(int m = 0;m <= i;m++){
// //             sum += grid[m][0];
// //         }
// //         return sum;
// //     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int upSum = grid[i][j] + minSum(i - 1, j, grid, dp);
//     int leftSum = grid[i][j] + minSum(i, j - 1, grid, dp);
//     return dp[i][j] = min(upSum, leftSum);
// }

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    // Recursion and then after that
    // We encountered many overlapping sub - problems
    // We used memoisation
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return minSum(n - 1, m - 1, grid, dp);
    
    // Tabulation
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, 0));
//     int sum = 0;
// //     // We know that in the first column we can only go up 
// //     // Therefore we will simply add the grid values we encounter in
// //     // our path
// //     for(int i = 0;i < n;i++){
// //         sum += grid[i][0];
// //         dp[i][0] = sum;
// //     }
// //     // We know that in the first row we can only move left 
// //     // Therefore we will simply add the grid values we encounter in
// //     // our path
// //     sum = 0;
// //     for(int i = 0;i < m;i++){
// //         sum += grid[0][i];
// //         dp[0][i] = sum;
// //     }
//     // Minimum path sum of 0,0 would be obviously the grid value itself
//     dp[0][0] = grid[0][0];
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             if(i == 0 && j == 0){
//                 dp[0][0] = grid[0][0];
//                 continue;
//             }
//             int up = grid[i][j], left = grid[i][j];
//             // requiring prev row's j column
//             if(i > 0)
//                 up += dp[i - 1][j];
//             else up += 1e9;
//             // requiring curr row's j - 1 column
//             if(j > 0)
//                 left += dp[i][j - 1];
//             else left += 1e9;
//             dp[i][j] = min(left, up);
//         }
//     }
//     return dp[n - 1][m - 1];
    
    // Space Optimisation;
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    
    for(int i = 0;i < n;i++){
        vector<int> curr(m, 0);
        for(int j = 0;j < m;j++){
            if(i == 0 && j == 0){
                curr[0] = grid[i][j];
                continue;
            }
            int up = grid[i][j], left = grid[i][j];
            if(i > 0)
                up += prev[j];
            else up += 1e9;
            if(j > 0)
                left += curr[j - 1];
            else
                left += 1e9;
            curr[j] = min(left, up);
        }
        prev = curr;
    }
    return prev[m - 1];
    
}