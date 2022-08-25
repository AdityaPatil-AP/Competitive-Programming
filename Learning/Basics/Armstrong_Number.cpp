#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Armstrong Numbers are those numbers if their order n(no. of digits) 
// then they satisfy abcde = pow(a, n) + pow(b, n) + pow(c, n) + pow(d, n) + pow(e, n);


int order(int n){
    int a = 0;
    while(n){
        a++;
        n/=10;
    }
    return a;
}

int power(int rem, int n){
    if(n == 0) return 1;
    if(n % 2 == 0)
        return power(rem, n/2) * power(rem, n/2);
    return rem * power(rem, n/2) * power(rem, n/2);
}

bool isArmstrong1(int n){
    int x = order(n);
    int temp = n;
    int sum = 0;
    while(n){
        int rem = n % 10;
        sum += power(rem, x);
        n /= 10;
    }
    return (sum == temp);
}

int findArmstrong(int n){
    int count = 0;
    for(int i = 1;i <= INT_MAX;i++){
        int sum = 0;
        int temp = i;
        // find the no. of digits;
        int num = (int)log10(temp) + 1;
        while(temp){
            int k = temp % 10;
            sum += pow(k, num);
            temp /= 10;
        }

        if(sum == i){
            count++;
        }
        if(count == n){
            return i;
        }
    }
}

string isArmstrong2(int n){
    string number = to_string(n);
    n = number.length();
    long long output = 0;
    for(char i : number){
        output += (long long int)pow(i - '0', n);
    }
    if(output == stoll(number)) return "True";
    else return "False";
}

void work(){
    // Armstrong Number
    // Approach 1;
    int n;
    cin >> n;
    cout << isArmstrong1(n) << endl;

    // Approach2 - in shorter way.
    // To find the no. of digits.
    int num = (int)log10(110) + 1;
    cout << num << endl;

    // Finding nth Armstrong Number.
    cin >> n;
    cout << findArmstrong(n) << endl;

    // Using numeric strings
    cin >> n;
    cout << isArmstrong2(n) << endl;
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


