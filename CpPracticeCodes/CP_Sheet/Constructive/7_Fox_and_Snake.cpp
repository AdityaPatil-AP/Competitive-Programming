#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Fox and Snake
    int r, c;
    cin >> r >> c;
    for(int i = 0;i < r;i++){
        if(i % 2 == 0){
            for(int j = 0;j < c;j++){
                cout << "#";
            }
            cout << endl;
        }
        else{
            if(i % 4 == 1){
                for(int j = 0;j < c - 1;j++){
                    cout << ".";
                }
                cout << "#" << endl;
            }
            if(i % 4 == 3){
                cout << "#";
                for(int j = 0;j < c - 1;j++){
                    cout << ".";
                }
                cout << endl;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


