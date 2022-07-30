#include <iostream>
using namespace std;

int coin_change(int n, int *d, int numD, int **output){
    // cout << n << " " << numD << endl;
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(numD == 0){
        return 0;
    }
    if(output[n][numD] > - 1){
        return output[n][numD];
    }
    int first = coin_change(n - d[0], d, numD, output);
    int second = coin_change(n, d + 1, numD - 1, output);
    output[n][numD] = first + second;
    return first + second;
}

int main(){
    int d[] = {1, 2, 5, 8, 9, 10, 15};
    // allocate a 2D array here. array dimension - n + 1, numD + 1
    // and put all -1, 
    int **output = new int*[100 + 1];
    for(int i = 0;i < 101;i++){
        output[i] = new int[8];
        for(int j = 0; j < 8;j++){
            output[i][j] = -1;
        }
    }
    cout << coin_change(100, d, 7, output) << endl;
    return 0;
}