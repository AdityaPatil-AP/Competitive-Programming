#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define ll long long int
// #, @, *, and &.
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
    int t;
    cin >> t;
    int f = t;
    while(t--){
    	string password;
    	int n;
    	cin >> n;
    	cin >> password;
	    int upperCaseCount = 0, lowerCaseCount = 0, specialChar = 0, digit = 0;
	    for(int i = 0;i < password.length();i++){
	    	int ascii = password[i];
	    	if(ascii >= 48 && ascii <= 57){
	    		digit++;
	    	}
	    	else if(ascii >= 65 && ascii <= 90){
	    		upperCaseCount++;
	    	}
	    	else if(ascii >= 97 && ascii <= 122){
	    		lowerCaseCount++;
	    	}
	    	else{
	    		specialChar++;
	    	}
	    }
	    if(specialChar < 1){
	    	password += '&';
	    }
	    if(upperCaseCount < 1){
	    	password += 'A';
	    }
	    if(lowerCaseCount < 1){
	    	password += 'a';
	    }
	    if(digit < 1){
	    	password += '1';
	    }
	    if(password.size() < 7){
	    	int addDigits = 7 - password.size();
	    	for(int i = 0; i < addDigits;i++){
	    		password += '1';
	    	}
	    }
	    cout << "Case #" << f - t  << ": " << password << endl;
	}
}