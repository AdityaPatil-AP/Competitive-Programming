#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

void work(){
    // My Try
    // Penalty - ShootOut.
    string s;
    while(cin >> s){
        // Handling the First 10 penalty Shoot-outs.
        ll goal1 = 0, goal2 = 0;
        bool done = false;
        for(int i = 0;i < 10;i++){
            if(i % 2 == 0){
                // TeamA
                goal1 += (s[i] - '0');
                ll shotRemB = (10 - i)/2;
                ll shotRemA = (10 - (i + 2))/2;
                // If he hits Chef can Win
                if(goal1 > goal2 + shotRemB){
                    cout << "TEAM-A " << i + 1 << endl;
                    done = true;
                    break;
                }
                // If he misses, Opponent can win.
                else if(goal2 > goal1 + shotRemA){
                    cout << "TEAM-B " << i + 1 << endl;
                    done = true;
                    break;
                }
            }
            else {
                // Team B
                goal2 += (s[i] - '0');
                ll shotRemA = (10 - i)/2;
                ll shotRemB = (10 - (i + 1))/2;
                // Similarly here, if opponent hits a goal, they
                // may win at that instant itself based on 
                // chefs goals and their remaining shots left.
                if(goal2 > goal1 + shotRemA){
                    cout << "TEAM-B " << i + 1 << endl;
                    done = true;
                    break;
                }
                // If the opponent misses, Chef can win if they 
                // have more goals than opponent goals + opponent shots
                // left.
                else if(goal1 > goal2 + shotRemB){
                    cout << "TEAM-A " << i + 1 << endl;
                    done = true;
                    break;
                }
            }
        }
        if(done == true) continue;
        // Which Means After 5 turns of each side we can't decide 
        // a winner.
        // Now we play sudden death. Each team will take one chance, 
        // The one with the highest score, if possible after every turn will be declared
        // winner.
        done = false;
        for(int i = 10;i < 20;i+=2){
            goal1 += s[i] - '0';
            goal2 += s[i + 1] - '0';
            if(goal1 > goal2) {
                cout << "TEAM-A " << i + 2 << endl;
                done = true;
                break;
            }
            else if(goal2 > goal1){
                cout << "TEAM-B " << i + 2 << endl;
                done = true;
                break;
            }
        }
        if(done == true) continue;
        // Or Else a Tie..
        cout << "TIE" << endl;
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


