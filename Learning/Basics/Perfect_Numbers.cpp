#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Perfect Numbers are those numbers which are equal to sum of all it's divisors
// excluding the number itself.


// Time Complexity - O(n)
bool perfectNumber1(int n){
    int sum = 0;
    for(int i = 1;i < n;i++){
        if(n % i == 0) sum += i;
    }
    if(sum == n) return true;
    return false;
}

bool perfectNumber2(int n){
    int sum = 1;
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            if(i * i != n)
                sum += (i + (n/i));
            else sum += i;
        }
    }
    if(sum == n && n != 1) return true;
    return false;
}

void work(){
    // Perfect Numbers.
    // Simple Approach.
    // Go from 1 to n - 1 and maintain a sum of all it's divisors.
    int n;
    cin >> n;
    cout << perfectNumber1(n) << endl;

    // Efficient Approach
    cout << perfectNumber2(n) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


