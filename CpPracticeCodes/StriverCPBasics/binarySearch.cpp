// #include <iostream>
// #include <algorithm>
// #include <climits>
// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverCPBasics\\input.txt","r", stdin);
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverCPBasics\\output.txt", "w", stdout);
    #endif

    // Binary search
    int arr[] = {1, 2, 4, 5};
    bool res = binary_search(arr, arr + 4, 3);
    bool res1 = binary_search(arr, arr + 4, 2);
    cout << res << " " << res1 << endl;
    
    // Lower_bound function
    int a[] = {1, 2, 5, 4, 6, 9, 9};
    int index = lower_bound(a, a + 6, 4) - a;// 1
    int index1 = lower_bound(a, a + 6, 7) - a;// 4;
    int index2 = lower_bound(a, a + 6, 10) - a; // 6
    cout << index << " " << index1 << " " << index2 << endl;

    // Incase of Vector 
    vector<int> v1 = {1, 4, 5, 6, 9, 9};
    int indexa = lower_bound(v1.begin(), v1.end(), 4) - v1.begin();// 1
    int indexa1 = lower_bound(v1.begin(), v1.end(), 7) - v1.begin();// 4;
    int indexa2 = lower_bound(v1.begin(), v1.end(), 10) - v1.begin(); // 6
    cout << indexa << " " << indexa1 << " " << indexa2 << endl;

    // Upper_bound function
    int a1[] = {8, 4, 2, 7, 0, 4, -1,-2};
    int indexb1 = upper_bound(a, a + 6,-3) - a;
    int indexb2 = upper_bound(a, a + 8, 7) - a;
    int indexb3 = upper_bound(a, a + 8, 10) - a;
    cout << indexb1 << " " << indexb2 << " " << indexb3 << endl;

    return 0;
}


