#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>


int main(){
    // vector<int> v(5);
    // vector<int> v1;
    // // for(int i = 0; i < v.size();i++){
    // //     v[i] = i + 1;
    // // }
    // for(int i = 0; i < 5;i++){
    //     v1.push_back(i + 1);
    // }
    // vector<int>::iterator it;
    // for(it = v1.begin();it != v1.end();it++){
    //     cout << *it << endl;
    // }
    // String
    // string s = "Aditya";
    // string s1(s, 2, 4);
    // cout << s << endl;
    // cout << s1 << endl;

    // string s2 = s.substr(1, 4);
    // cout << s2 << endl;
    // if(s1.compare(s2)){
    //     cout << s1 << " is equal to " << s2 << endl; 
    // }
    // else{
    //     cout << s1 << " is not equal to " << s2 << endl;
    // }
    // Pair
    // pair<int, char> p;
    // p = make_pair(2, 'b');
    // pair<int, char> p2(1, 'a');

    // cout << p.first << " " << p.second << endl;
    // cout << p2.first << " " << p2.second << endl;

    // Set
    // set<int> s;
    // int arr[] = {1,2,3,4,5,6,5};
    // for(int i = 0; i < 7;i++){
    //     s.insert(arr[i]);
    // }
    // set<int>::iterator it;
    // for(it = s.begin();it != s.end();it++){
    //     cout << *it << endl;
    // }
    // if(s.find(7) == s.end()){
    //     cout << "Element Not found " << endl;
    // }
    // else{
    //     cout << "Element found " << endl;
    // }

    // Map
    // int arr[] = {1, 2, 3, 4, 5, 6, 5};
    // map<int, int> a;
    // for(int i = 0; i < 7;i++){
    //     a[arr[i]] = a[arr[i]] + 1;
    // }

    // map<int, int>::iterator it;
    // for(it = a.begin();it != a.end();it++){
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << endl;
    // a.erase(1);
    // for(it = a.begin();it != a.end();it++){
    //     cout << it->first << " " << it->second << endl;
    // }

    // Unordered_map
    int arr[] = {1, 2, 3, 4, 5, 6, 5};
    unordered_map<int, int> a;
    for(int i = 0; i < 7;i++){
        a[arr[i]] = a[arr[i]] + 1;
    }

    unordered_map<int, int>::iterator it;
    for(it = a.begin();it != a.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    a.erase(1);
    for(it = a.begin();it != a.end();it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}