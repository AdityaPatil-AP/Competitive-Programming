#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;
    for(int i = 0; i < n;i++){
        if(arr[i] > 0){
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(1, min_ending_here*arr[i]);
        }
        else if(arr[i] == 0){
            min_ending_here = 1;
            max_ending_here = 1;
        }
        else{
            int temp = max_ending_here;
            max_ending_here = max(1, min_ending_here * arr[i]);
            min_ending_here = temp*arr[i];

        }
        max_so_far = max(max_so_far, max_ending_here);
    }
    cout << "Maximum Product Subarray : " << max_so_far << endl;
    return 0;
}