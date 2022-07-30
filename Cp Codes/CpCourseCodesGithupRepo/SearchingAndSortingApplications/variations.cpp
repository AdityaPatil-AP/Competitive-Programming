#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int binarySearch(int *arr, int start, int end, int k){
    int ans = -1;
    int m = start - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] - arr[m] >= k){
            end = mid;
            ans = mid;
        } 
        else{
            start = mid + 1;
        }
    }
    return ans;
}

long variationPairs(int *arr, int n, int k){
    sort(arr, arr + n);
    // Two pointer approach...
    // int i = 0, j = 1;
    // long count = 0;
    // while(j < n){
    //     if(arr[j] - arr[i] >= k){
    //         count += (n - j);
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }
    // }

    // Using Binary Search..
    long count = 0;
    for(int i = 0; i < n;i++){
        int j = i + 1;
        count += (binarySearch(arr, j, n - 1, k) + 1);
    }
    return count;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    auto start1 = high_resolution_clock::now();
    long count = variationPairs(arr, n, k); 
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << count << " " << duration.count() << endl;
    return 0;
}