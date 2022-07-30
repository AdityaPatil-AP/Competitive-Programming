#include <iostream>
using namespace std;

int main(){
    // Creating Strings dynamically...
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;
    cout << *sp << endl;
    
    string s = "abc";
    // cin >> s; 
    // getline(cin, s);
    // cout << s << endl;

    s = "defdef";
    cout << s[0] << endl;
    s[0] = 'a';

    string s1;
    s1 = "def";

    string s2 = s + s1;
    s2 += s1;
    cout << s2 << endl;

    cout << s1 << endl;
    cout << s << endl;
    // Finding length
    cout << s.size() << endl;
    cout << s.length() << endl;
    // Getting Substring.
    cout << s.substr(0,3) << endl;

    cout << s.find("deg") << endl;
    return 0;
}