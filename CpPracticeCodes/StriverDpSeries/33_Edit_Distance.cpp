int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
    // Base Case
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // Explorations
    if(str1[i - 1] == str2[j - 1]){
        return dp[i][j] = 0 + f(i - 1, j - 1, str1, str2, dp);
    }
    else{
        // Insert
        int option1 = 1 + f(i, j - 1, str1, str2, dp);
        // Delete
        int option2 = 1 + f(i - 1, j, str1, str2, dp);
        // Replace
        int option3 = 1 + f(i - 1, j - 1, str1, str2, dp);
        return dp[i][j] = min(option1, min(option2, option3));
    }
}

int editDistance(string str1, string str2)
{
    //write you code here
//     int n = str1.size();
//     int m = str2.size();
//     // Recursion and Memoisation
//     // Converted to 1 based indexing so that it's easy in tabulation
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//     return f(n, m, str1, str2, dp);
    
    // Tabulation Way
//     int n = str1.size();
//     int m = str2.size();
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//     for(int i = 0;i <= n;i++) dp[i][0] = i;
//     for(int j = 0;j <= m;j++) dp[0][j] = j;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(str1[i - 1] == str2[j - 1]){
//                 dp[i][j] = 0 + dp[i - 1][j - 1];
//             }
//             else{
//                 // Insert
//                 int option1 = 1 + dp[i][j - 1];
//                 // Delete
//                 int option2 = 1 + dp[i - 1][j];
//                 // Replace
//                 int option3 = 1 + dp[i - 1][j - 1];
//                 dp[i][j] = min(option1, min(option2, option3));
//             }
//         }
//     }
//     return dp[n][m];
    
    // Space Optimisation - 2 - 1d arrays
//     int n = str1.size();
//     int m = str2.size();
//     vector<int> curr(m + 1, 0);
//     vector<int> prev(m + 1, 0);
//     for(int i = 0;i <= m;i++) prev[i] = i;
//     for(int i = 1;i <= n;i++){
//         curr[0] = i;
//         for(int j = 1;j <= m;j++){
//             if(str1[i - 1] == str2[j - 1]){
//                 curr[j] = 0 + prev[j - 1];
//             }
//             else{
//                 // Insert
//                 int option1 = 1 + curr[j - 1];
//                 // Delete
//                 int option2 = 1 + prev[j];
//                 // Replace
//                 int option3 = 1 + prev[j - 1];
//                 curr[j] = min(option1, min(option2, option3));
//             }
//         }
//         prev = curr;
//     }
//     return prev[m];
    
    // Space Optimisation - 1d array 

    // can't be done as it also requires current row's prev element as well 
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0);
    for(int i = 0;i <= m;i++) prev[i] = i;
    for(int i = 1;i <= n;i++){
       prev[0] = i;
        for(int j = 1;j <= m;j++){
            if(str1[i - 1] == str2[j - 1]){
                continue;
            }
            else{
                // Insert
                int option1 = 1 + prev[j - 1];
                // Delete
                int option2 = 1 + prev[j];
                // Replace
                int option3 = 1 + prev[j - 1];
                prev[j] = min(option1, min(option2, option3));
            }
        }
    }
    return prev[m];
}