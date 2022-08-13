#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Arrival of the General
    int n;
    cin >> n;
    map<int, int> problem;
    problem[0] = 0;
    problem[1] = 0;
    for(int i = 0;i < n;i++){
        int response;
        cin >> response;
        problem[response]++;
    }
    if(problem[1] > 0){
        cout << "HARD" << endl;
    }
    else{
        cout << "EASY" << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\Implementation\\Constructive\\output.txt", "w", stdout);
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


