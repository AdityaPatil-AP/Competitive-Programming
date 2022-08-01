#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    int n;
    cin >> n;
    int *arr = new int[n];
    // We will see the first reoccuring element from the back
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    set<int> m;
    int count = 0;
    for(int i = n - 1;i >= 0;i--){
        m.insert(arr[i]);
        if(m.size() == (count + 1)){
            count += 1;
            continue;
        }
        else{
            break;
        }
    }
    cout << n - count << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}