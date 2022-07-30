#include <iostream>
using namespace std;

void printArray(int a[][100], int m, int n){
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int a[100][100];
    int m, n;
    cin >> m;
    cin >> n;

    // Taking Input
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            cin >> a[i][j];
        }
    }

    printArray(a, m, n);

    /*
    // print array row wise 
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}