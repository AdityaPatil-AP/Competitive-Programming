#include <bits/stdc++.h>
using namespace std;

int modExpR(int a, int b, int c){
    if(a == 0){
        return 0;
    }
    if(b == 0){
        return 1;
    }
    // if b is even
    long long ans;
    if(b % 2 == 0){
        long long smallAns = modExpR(a, b/2, c);
        ans = (smallAns * smallAns)%c;
    }
    else{
        long smallAns = modExpR(a, b - 1, c);
        ans = a % c;
        ans = (ans * smallAns)%c;
    }
    return (int)((ans + c)%c);
}

int modExpI(int a, int b, int c){
    long long ans = 1;
    while(b != 0){
        if(b & 1 == 1){
            ans = (ans * (a%c))%c;
        }
        a = ((a%c) * (a%c))%c;
        b = b/2;
    }
    return (int)(ans + c)%c;
}

int main(){
    int a = -5;
    long long b = 4353;
    int c = 6;
    cout << modExpR(a, b, c) << endl;
    cout << modExpI(a, b, c) << endl;
    return 0;
}