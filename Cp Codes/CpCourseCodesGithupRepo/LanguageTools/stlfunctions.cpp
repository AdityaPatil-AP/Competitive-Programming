#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <utility>

struct Interval{
    int st;
    int et;
};

bool compare(Interval i1, Interval i2){
    return i1.st > i2.st;
}

int main(){
    // Sort Function
    // Interval arr[] = {{6,4}, {3,4}, {4,6}, {8,13}};
    // sort(arr, arr+4,compare);
    int arr[] = {1, 3, 2, 3, 7, 5, 6};
    // Increasing Order
    sort(arr, arr + 7);
    // Decreasing Order 
    // sort(arr, arr + 6, greater<int>());
    for(int i = 0; i < 7;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // Binary Search
    cout << binary_search(arr, arr + 7, 8) << endl;

    // lower_bound
    cout << lower_bound(arr, arr + 7, 3) - arr << endl;

    //upper_bound 
    cout << upper_bound(arr, arr + 7, 3) - arr << endl;

    // gcd 
    cout << __gcd(45, 6) << endl;

    //power
    cout << pow(10.23, 5) << endl;

    int x = 10;
    int y = 12;
    swap(x,y);
    cout << x << " " << y << endl;

    cout << max(14, 18) << endl;
    cout << min(10, 12) << endl;

    // cout << reverse();

    // for(int i = 0; i < 4;i++){
    //     cout << arr[i].st << " : " << arr[i].et << endl;
    // }
    return 0;
}