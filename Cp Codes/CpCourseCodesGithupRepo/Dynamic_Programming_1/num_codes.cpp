#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int num_codes(int* n, int size){
    if(size == 1){
        return 1;
    }
    if(size == 0){
        return 1;
    }
    int output = num_codes(n, size - 1);
    if(n[size - 2] * 10 + n[size - 1] <= 26){
        output += num_codes(n, size - 2); 
    }
    return output;
}

int num_codes2(int* n, int size, int *arr){
    if(size == 1){
        return 1;
    }
    if(size == 0){
        return 1;
    }
    if(arr[size] > 0){
        return arr[size];
    }
    int output = num_codes(n, size - 1);
    if(n[size - 2] * 10 + n[size - 1] <= 26){
        output += num_codes(n, size - 2); 
    }
    arr[size] = output;
    return output;
}

int num_codes_i(int *input, int size){
    int* output = new int[size + 1]{};
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= size;i++){
        output[i] = output[i - 1];
        if(input[i - 2] * 10 + input[i - 1]  <= 26)
            output[i] += output[i - 2];
    }
    int ans = output[size];
    delete [] output;
    return ans;
}

int main(){
    int input[] = {1, 0, 0, 1, 1, 3, 4, 2, 1, 9 , 3};
    int *arr = new int[5];
    // cout << num_codes2(input, 4, arr) << endl;
    // cout << num_codes_i(input, 4) << endl;
    auto start1 = high_resolution_clock::now();
    cout << num_codes(input, 11) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << duration.count() << endl;
    return 0;
}