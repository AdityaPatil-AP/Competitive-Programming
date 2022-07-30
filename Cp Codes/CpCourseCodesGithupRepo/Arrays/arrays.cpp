#include <iostream>
#include <climits>

using namespace std;

void printArray(int input[], int a){
    // cout << "Function : " <<  sizeof(input) << endl;
    cout << "Print : " << endl;
    for(int i = 0; i < a; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

void increment(int a, int b[], int n){
    a++;
    b[0]++;
}

void reverse(int input[], int n){
    int i = 0, j = n - 1;
    while(i < j){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}

int main(){

    int a = 10;
    int b[10] = {1, 2, 3, 4, 5};
    printArray(b, 5);
    reverse(b, 5);
    printArray(b, 5);

    /*
    increment(a, b, 10);

    cout << "a : " << a << endl;
    cout << "b[0] : "  << b[0] << endl;

    int input[100] = {1, 2, 3};
    */
    // printArray(input, 100);
    /*
    // Take array input from the user
    int n;
    cout << "Enter n : " << endl;
    cin >> n;
    int input[100];

    cout << input << endl;
    
    cout << "Enter array elements  : " << endl;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    cout << "Main : " << sizeof(input) << endl;
    printArray(input, n);
    */
    /*
    int input[100];

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    // Printing the Array
    for(int i = 0; i < n; i++){
        cout << input[i] << endl;
    }

    // Finding the maximum value in the array;
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(input[i] > max){
            max = input[i];
        }
    }

    cout << "Max : " << max << endl;
    */

    return 0;
}