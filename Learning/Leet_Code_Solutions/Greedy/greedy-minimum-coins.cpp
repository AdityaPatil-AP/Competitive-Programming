#include <iostream>
using namespace std;

int solve(int value){
    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans = 0;
    for(int i = 8;i >= 0;i--){
        while(denominations[i] <= value){
            value -= denominations[i];
            ans++;
        }
    }
    return ans;
}

int main(){
    int value;
    cin >> value;
    cout << solve(value) << endl;
    return 0;
}