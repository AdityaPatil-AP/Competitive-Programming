#include <iostream>
using namespace std;
#include <cstring>

void printAllPrefixes(char input[]){

    // i represents end index of my prefix
    for(int i =0; input[i] != '\0'; i++){
        // j represents start index of my prefix
        for(int j = 0; j <= i;j++){
            cout << input[j];
        }
        cout << endl;
    }
}

int main(){
    
    char input[100] = "abcd";
    printAllPrefixes(input);
    /*
    char input1[100] = "abcdefghi", input2[100] = "hello";
    // cin >> input1;
    // cin >> input2;

    cout << "Before Copying : " << endl;
    cout << "Input 1 : " << input1 << endl;
    cout << "Input 2 : " << input2 << endl;
    cout << "After Copying : " << endl;
    strncpy(input1, input2,7);
    // or strcpy(input1, "hello1");
    cout << "Input 1 : " << input1 << endl;
    cout << "Input 2 : " << input2 << endl;
    */
    /*
    if(strcmp(input1, input2) == 0){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    */
    /*
    int len = strlen(input);

    cout << "Length : " << len << endl;
    */
    return 0;
}