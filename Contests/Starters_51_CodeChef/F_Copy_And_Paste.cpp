#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n, m;
    cin >> n >> m;
    string bs;
    cin >> bs;
    int size = n;
    int arr[size + 1][2] = {0, 0};
    int sumFromStart = 0, sumFromEnd = 0;
    for(int i = 0, j = size - 1;i < size && j >= 0;i++, j--){
        sumFromStart += (bs[i] - '0');
        sumFromEnd += (bs[j] - '0');
        arr[i][0]= sumFromStart;
        arr[j][1] = sumFromEnd;
    }
    int goodIndices = 0;
    for(int i = 0;i < size;i++){
        if(arr[i][0] == arr[i + 1][1]){
            goodIndices++;
        }
    }
    if(size % 2 == 0){
        if(goodIndices == size){
            cout << size * m << endl;
        }
        else{
            cout << goodIndices << endl;
        }
    }
    else{
        if(goodIndices == size){
            cout << goodIndices * m << endl;
        }
        else if(m%2 == 0 && goodIndices != 0){
            cout << 1 << endl;
        }
        else if(m%2 == 1 && goodIndices != 0){
            cout << goodIndices << endl;
        }
        else if(m%2 == 1 && goodIndices == 0){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
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
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}