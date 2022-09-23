#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

// const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    int count0, count1;
    cin >> count0 >> count1;
    // if count0 is odd and count1 is even 
    if(count0 % 2 == 1 && count1 % 2 == 0){
        // Then count0 should be greater than 1 and 
        // count1 greater than equal to 2;
        if(count0 > 1 && count1 >= 2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    // If the number of zeroes and the number of 1's are odd
    // then the palindrome cannot be made.
    else if(count0 % 2 == 1 && count1 % 2 == 1){
        cout << "NO" << endl;
    }
    // similar to odd even case.
    else if(count0 % 2 == 0 && count1 % 2 == 1){\
        if(count0 >= 2 && count1 > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    // if both the count0 and count1 is even then
    // it is always possible to create binary Palindrome.   
    else{
        cout << "YES" << endl;
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


