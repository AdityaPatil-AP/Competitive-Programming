#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n;i++){
        int current = arr[i];
        int j;
        for(int j = i - 1;j >= 0; j--){
            if (current < arr[j]){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j + 1] = current;
    }
}

void selectionSort(int input[], int n){
    // Find min element of the array
    for(int j = 0; j < n - 1;j++){
        int min = input[j], minIndex = j;
        for(int i = j + 1; i < n; i++){
            if(input[i] < min){
                min = input[i];
                minIndex = i;
            }
        }
        int temp = input[minIndex];
        input[minIndex] = input[j];
        input[j] = temp;
    }
}

int main(){
    int input[] = {3, 1, 6, 9};
    insertionSort(input, 4);
    for(int i = 0; i < 4; i++){
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}