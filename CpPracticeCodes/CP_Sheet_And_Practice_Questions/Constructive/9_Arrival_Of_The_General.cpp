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
    vector<int> line(n);
    for(int i = 0;i < n;i++){
        cin >> line[i];
    }
    int maxi = max_element(line.begin(), line.end()) - line.begin();
    int minelement = *min_element(line.begin(), line.end());
    int mini;
    for(int i = n - 1;i>= 0;i--){
        if(line[i] == minelement){
            mini = i;
            break;
        }
    }
    if(maxi < mini){
        cout << maxi + (line.size() - mini - 1) << endl;
    }
    else if(maxi > mini){
        cout << maxi + (line.size() - mini - 2) << endl;
    }
    else{
        cout << 0 << endl;
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


