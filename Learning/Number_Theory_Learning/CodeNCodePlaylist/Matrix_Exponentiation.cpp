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

const int N = 105;
#define pb push_back

int arr[N][N] , I[N][N];

void multiplication(int first[][N], int second[][N], int dim){
    // ll helper[dim + 1] = {0};
    int helper[dim + 1][dim + 1];
    for(int i = 0;i < dim;i++){
        // We will compute the whole row first and then we update the 
        // values of that row for the I....
        // helper array will store the row for the time being.
        for(int j = 0;j < dim;j++){
            ll temp = 0;
            for(int k = 0;k < dim;k++){
                temp = (temp + (1ll * first[i][k] * second[k][j]) % mod)%mod;
            }
            helper[i][j] = temp;
        }
        // Here 1d array approach will fail, because when the first and second are both arr
        // then we are ultimately updating the arr itself which will lead to wrong answer.
        // So, in that case we will require another array.
        // for(int j = 0;j < dim;j++){
        //     first[i][j] = helper[j];
        // }
    }
    for(int i = 0;i < dim;i++){
        for(int j = 0;j < dim;j++){
            first[i][j] = helper[i][j];        }
    }

    return;
}

void power(int arr[][N], int dim, int n){
    for(int i= 0;i <dim;i++){
        for(int j = 0;j < dim;j++){
            if(i == j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
    // This loop takes linear time for calculation of arr^n.
    // for(int i = 1;i <= n;i++){
    //     multiplication(I, arr, dim); // Simply Meaning I = I * A;
    // }

    // To do this multiplication in O(log(n)) time.
    while(n){
        if(n % 2){
            multiplication(I, arr, dim);
            n--;
        }
        else{
            multiplication(arr, arr, dim);
            n = n/2;
        }
    }

    for(int i = 0;i < dim;i++){
        for(int j = 0;j < dim;j++){
            arr[i][j] = I[i][j];
        }
    }
    return;
}

void printMat(int arr[][N], int dim){
    for(int i = 0;i < dim;i++){
        for(int j = 0;j < dim;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void work(){
    // Naive Approach
    int dim, n;
    cin >> dim >> n;
    for(int i = 0;i < dim;i++)
        for(int j = 0;j < dim;j++)
            cin >> arr[i][j];

    power(arr, dim, n);
    printMat(arr, dim);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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


