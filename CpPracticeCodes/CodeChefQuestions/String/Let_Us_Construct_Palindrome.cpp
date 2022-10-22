#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

bool isPalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

bool isPalindrome(string &s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

void work(){
    // My Try
    // Let Us Construct Palindrome.
    // string s;
    // cin >> s;
    // // This indicates whether I can delete the current Character or not.
    // bool flag = true;
    // // Indicating a palindrome can be made after deleting a character.
    // bool ans = true;
    // int i = 0, j = s.size() - 1;
    // while(i < j){
    //     if(s[i] == s[j]){
    //         i++,j--;
    //     }
    //     else if((s[i] == s[j - 1] && flag == true)){
    //         i++, j-=2;
    //         // I have deleted a character.
    //         flag = false;
    //     }
    //     else if(s[i + 1] == s[j] && flag == true){
    //         flag = false;
    //         i+=2;
    //         j--;
    //     }
    //     else {
    //         ans = false;
    //         break;
    //     }
    // }
    // if(ans) cout << "YES" << endl;
    // else cout << "NO" << endl; 
    // return;


    // Submissions Reference.
    // 1)
    // string s;
    // cin >> s;
    // int i = 0, j = s.size() - 1;
    // if(isPalindrome(s, i, j)) cout << "YES" << endl;
    // else{
    //     while(i <= j){
    //         if(s[i] == s[j]) i++, j--;
    //         else{
    //             if(isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)){
    //                 cout << "YES" << endl;
    //             }
    //             else {
    //                 cout << "NO" << endl;
    //             }
    //             break;
    //         }
    //     }
    // }

    // Reference 2.
    string s, s1;
    cin >> s;
    int i = 0, j = s.size() - 1;
    s1 = s;
    while(i < j){
        if(s[i] != s[j]){
            s.erase(i, 1);
            if(isPalindrome(s)){
                cout << "YES" << endl;
                return;
            }
            s = s1;
            s.erase(j , 1);
            if(isPalindrome(s)){
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        i++,j--;
    }
    cout << "YES" << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


