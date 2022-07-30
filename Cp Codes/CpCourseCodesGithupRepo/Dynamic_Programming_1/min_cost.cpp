#include <bits/stdc++.h>
using namespace std;
using namespace chrono;


// Recursively 
int min_cost(int **input, int si, int sj, int ei, int ej, int **output){
    if(si == ei && sj == ej){
        return input[ei][ej];
    }
    if(si > ei || sj > ej ){
        return INT_MAX;
    }   
    if(output[si][sj] > -1){
        return output[si][sj];
    }
    int option1 = min_cost(input, si + 1, sj, ei, ej, output);
    int option2 = min_cost(input, si + 1, sj + 1,ei, ej, output);
    int option3 = min_cost(input, si, sj + 1, ei, ej, output);
    int a = input[si][sj] + min(option1, min(option2, option3));
    output[si][sj] = a;
    return a;
}

// Iteratively
int min_cost2(int **input, int m, int n){
    int **dp = new int*[m];
    for(int i = 0;i < m;i++){
        dp[i] = new int[n];
    }
    dp[m - 1][n - 1] = input[m - 1][n - 1];
    for(int j = m - 2; j >= 0; j--){
        dp[j][n - 1] = input[j][n - 1] + dp[j + 1][n - 1];
    }

    for(int j = n - 2; j >= 0;j--){
        dp[m - 1][j] = dp[m - 1][j + 1] + input[m - 1][j];
    }
    for(int i = m - 2;i >= 0;i--){
        for(int j = n - 2; j>=0;j--){
            dp[i][j] = input[i][j] + (min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1])));
        }
    }
    int ans = dp[0][0];
    for(int i = 0; i < n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int **input = new int*[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];
    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;
    int **output = new int*[4];
    for(int i = 0; i < 4;i++){
        output[i] = new int[4];
        for(int j = 0;j < 4;j++){
            output[i][j] = -1;
        }
    }
    auto start1 = high_resolution_clock::now();
    // std::cout << min_cost(input, 0, 0, 2, 2, output) << endl;
    std::cout << min_cost2(input, 3,3) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    std::cout << "Time : " << duration.count();
    
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
    delete [] input;  
    return 0;
}