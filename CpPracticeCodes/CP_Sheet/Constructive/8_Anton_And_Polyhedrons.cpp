#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // Anton and Polyhedrons
    // int n;
    // cin >> n;
    // int faces = 0;
    // for(int i = 0;i < n;i++){
    //     string s;
    //     cin >> s;
    //     if(s == "Icosahedron"){
    //         faces += 20;
    //     }
    //     else if(s == "Cube"){
    //         faces += 6;
    //     }
    //     else if(s == "Tetrahedron"){
    //         faces += 4;
    //     }
    //     else if(s == "Octahedron"){
    //         faces += 8;
    //     }
    //     else{
    //         faces += 12;
    //     }
    // }
    // cout << faces << endl;

    // Tutorial Solution
    // Use map instead of string matching
    map<string, int> values;
    values["Tetrahedron"] = 4;
    values["Cube"] = 6;
    values["Octahedron"] = 8;
    values["Dodecahedron"] = 12;
    values["Icosahedron"] = 20;

    int n;
    cin >> n;
    int res = 0;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        res += values[s];
    }
    cout << res << endl;
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


