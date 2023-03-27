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

    ll n, m, i1, j1, i2, j2;
    string s;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> s;
    
    map<string, pair<int, int>> mp;
    mp["DR"] = {1, 1};
    mp["DL"] = {1, -1};
    mp["UL"] = {-1, -1};
    mp["UR"] = {-1, 1};

    map<string, string> changeEdge;
    map<string, string> changeCorner;

    changeEdge["DL"] = "UL";
    changeEdge["DR"] = "UR";
    changeEdge["UL"] = "DL";
    changeEdge["UR"] = "DR";

    changeCorner["DL"] = "UR";
    changeCorner["DR"] = "UL";
    changeCorner["UL"] = "DR";
    changeCorner["UR"] = "DL";

    int hits = 0;
    int cornerEncountered = 0;
    bool found = true;
    string dir = s;
    if(i1 == )
    while(true){
        if(i1 == i2 && j1 == j2){
            break;
        }
        if((i1 == n || i1 == 1) && (j1 == 1 || j1 == m)){
            cornerEncountered++;
            hits++;
            dir = changeCorner[dir];
            i1 += mp[dir].first;
            j1 += mp[dir].second;
            if(cornerEncountered == 2){
                found = false;
                break;
            }
        }
        if(i1 == n || i1 == 1 || j1 == m || j1 == 1){
            dir = changeEdge[dir];
            hits++;
            i1 += mp[dir].first;
            j1 += mp[dir].second;
        }
        i1 += mp[dir].first;
        j1 += mp[dir].second;
    }

    if(found){
        cout << hits << endl;
    }
    else{
        cout << "-1" << endl;
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


