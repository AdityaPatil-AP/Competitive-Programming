// Recursion + memoization

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0;i <= 2;i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    int maxi = 0;
    for(int i = 0;i <= 2;i++){
        if(i != last){
            int p = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(p, maxi);
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // Memoization done
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return f(n - 1, 3, points, dp);
}

// Recursion to Tabulation

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0;i <= 2;i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    int maxi = 0;
    for(int i = 0;i <= 2;i++){
        if(i != last){
            int p = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(p, maxi);
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // Memoization done
    vector<vector<int>> dp(n, vector<int> (4, -1));
//     return f(n - 1, 3, points, dp);
    
    for(int last = 0;last <= 3;last++){
        int maxi = 0;
        for(int i = 0;i <= 2;i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        dp[0][last] = maxi;
        
       for(int i = 1;i < n;i++){
           for(int last = 0;last <= 3;last++){
               int maxp = 0;
               for(int j = 0;j <= 2;j++){
                   if(j != last){
                       maxp = max(maxp, points[i][j] + dp[i - 1][j]);
                   }
               }
               dp[i][last] = maxp;
           }
       }
    }
    
    return dp[n - 1][3];
}

// Space Optimisation


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // Memoization done
    vector<int> prev(3, 0);
//     return f(n - 1, 3, points, dp);
    
    for(int last = 0;last <= 3;last++){
        int maxi = 0;
        for(int i = 0;i <= 2;i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        prev[last] = maxi;
    }
        
    for(int i = 1;i < n;i++){
        vector<int> temp(4, 0);
        for(int last = 0;last <= 3;last++){
            int maxp = 0;
            for(int j = 0;j <= 2;j++){
                if(j != last){
                    maxp = max(maxp, points[i][j] + prev[j]);
                }
            }
            temp[last] = maxp;
        }
        prev = temp;
    }
    
    return prev[3];
}