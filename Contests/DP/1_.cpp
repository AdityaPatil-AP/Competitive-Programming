#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Macros list.


#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

// GitHub Repository for Large Code Implementations.


// After solving the problem, look for solution of higher rated person.
// Understand what optimisation he has done.

// Prove your problem correctness. Why only this work here?

// See the constraints, and solve it, don't over optimise.

// Always read the editorial for an unsolved problem.

// You are almost there, Don't stop now. Great Thing takes time.
// If you think, there is another idea that may work, go for it as well!!

void work(){
    // My Try :
    // A) 

    ll a, b, c;
    cin >> a >> b >> c;
    if((a + b) == c){
        cout << "+" << endl;
    }
    else{
        cout << "-" << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



// Macros list.

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back



int grid[n][m]; // Input Matrix

int dp[n][m]; // Assume value here is -1.

// subproblem : f(i, j) represents minimum sum path from (i, j) to 
// to (n - 1, m - 1).
int f(int i , int j){
    if(i >= n || j >= m)
        return INT_MAX;
    if(i == n - 1 && j = m - 1){
        return grid[n - 1][m - 1];
    }

    if(dp[i][j] != -1) // this state has been calculated before.
        return dp[i][j];

    return dp[i][j] = grid[i][j] + min(f(i, j + 1), f(i + 1, j));    
}



// GitHub Repository for Large Code Implementations.



// You are almost there, Don't stop now.

void work(){
    // My Try :
    // A) 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


