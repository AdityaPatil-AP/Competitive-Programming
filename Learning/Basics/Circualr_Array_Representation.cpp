#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Theory 
// An array is called circular array if we consider the first element after
// the last element.

// Task : is to print all the element starting from that person
// Given char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};

// if we give 'b' then print all the other person after b 
// The order should be like this : 
// 'b', 'c', 'd', 'e', 'f', 'g', 'a'

// Linear Search
int find(char *arr,int n, char start){
    int i;
    for(i = 0;i < n;i++){
        if(arr[i] == start){
            return i;
        }
    }
    return 0;
}

void print(char start, char *arr, int n){
    char temp[(2 * n)];
    int ind = find(arr, n, start);
    for(int i = 0;i < n;i++){
        temp[i] = temp[n + i] = arr[i];
    }
    for(int i = ind;i < ind + n;i++){
        cout << temp[i] << " ";
    }
    cout << endl;
}

void printmod(char *arr, int n, int ind){
    for(int i = ind;i < ind + n;i++){
        cout << arr[i%n] << " ";
    }
    cout << endl;
}

void work(){
    // 1st Approach is by creating an auxiliary space of (2 * n)
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = sizeof(arr)/sizeof(arr[0]);
    print('D' ,arr, n);

    // 2nd Approach - Using Mod Operator.
    // Data - if we carefully observe after the (n - 1)th index
    // we come back again to the 0th index.
    // So the basic intuition that comes to mind is that after every
    // i = i % n;
    // i will always be in the range of 0 <= i <= (n - 1).
    // To make someone remain in the same range we use modulus operator.
    // Thereofore, Using this methodology we can print the array starting 
    // from any index using the same array itself.
    char start;
    cin >> start;
    int ind = find(arr, n, start);
    printmod(arr, n, ind); 

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


