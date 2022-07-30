#include <iostream>
using namespace std;

void removeX(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != 'x'){
        removeX(s + 1);
    }
    else{
        int i;
        for(i = 1; s[i] != '\0';i++){
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i]; 
        removeX(s);
    }
}

int length(char s[]){
    // Base case
    if(s[0] == '\0'){
        return 0;
    }
    int smallStringLength = length(s + 1);
    return 1 + smallStringLength;
}

int main(){
    // char str[100];
    // cin >> str;

    // int l = length(str);
    // cout << l << endl;

    // removeX(str);

    // l = length(str);
    // cout << l << endl;.

    string str;
    cin >> str;
    cout << str << " " << str.size() << endl;
    str[2] = '\0';
    cout << str << " " << str.size() << endl;

    return 0;
}