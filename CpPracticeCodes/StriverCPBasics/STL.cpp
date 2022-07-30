// #include <iostream>
// #include <algorithm>
// #include <climits>
// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverCPBasics\\input.txt","r", stdin);
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverCPBasics\\output.txt", "w", stdout);
    #endif

    // Pairs
    cout << "Pairs : " << endl;
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}};

    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {2 , 5}, {5, 1}};

    cout << arr[1].second << endl;


    // Vectors 
    cout << "Vectors : " << endl;

    // An Empty Vector
    vector<int> v; // {}

    v.push_back(1); // {1}
    v.emplace_back(2); // {1, 2}

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    // Vector of size 5 with everyone initialised as 100
    vector<int> v2(5, 100); //{100, 100, 100, 100,100};

    vector<int> v3(5, 20); // {0, 0, 0, 0, 0};

    vector<int> v4(v3); // {20, 20, 20, 20, 20};

    // Take the vector to be{10, 20, 30, 40};
    vector<int> v5 = {10, 20, 30, 40, 50, 60};
    vector<int>::iterator it = v5.begin();

    it++;
    cout << *(it) << endl; // prints 20

    it = it + 2;
    cout << *(it) << endl; // prints 40

    vector<int>::iterator it1 = v5.end();
    // vector<int>::iterator it2 = v2.rend();
    // vector<int>::iterator it3 = v2.rbegin();

    // Ways to print the vector

    for(vector<int>::iterator it = v5.begin();it != v5.end();it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it = v5.begin();it != v5.end();it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it:v5){
        cout << it << " ";
    }
    cout << endl;

    // Erase an element
    // {10, 20, 12, 23}
    v5.erase(v5.begin()); // erase 10 {20, 12, 23}

    // {10, 20, 12, 23, 35}
    v5.erase(v5.begin() + 2,v5.begin() + 4); // {10, 20, 35}

    // Insert an element
    cout << "Insert : " << endl;
    vector<int> vec1(2, 100); // {100, 100}
    vec1.insert(vec1.begin(), 300); // {300, 100, 100}
    vec1.insert(vec1.begin() + 1, 2, 10); // {300, 10, 10, 100, 100};

    vector<int> copy(2, 50);
    vec1.insert(vec1.begin(), copy.begin(), copy.end());// {50, 50, 300, 10, 10, 100, 100};
    for(auto it : vec1){
        cout << it << " ";
    }
    cout << endl;
    cout << vec1.front() << " " << vec1.back() << endl;
    // Size 
    cout << "Size : " << endl;
    cout << vec1.size() << endl;

    // Delete an element from the back
    vec1.pop_back(); // {10}

    // Swap : 
    // vec1 -> 
    // v5
    cout << "Swap : " << endl;
    vec1.swap(v5);
    v5.clear();  // erases the entire vector

    cout << !v.empty() << endl;


    // List 
    cout << "List : " << "\n";

    list <int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(20); // {20, 5, 2, 4}

    // Ways to traverse the list ..
    for(int it : ls){
        cout << it << " ";
    }
    cout << "\n";
    for(list<int>::iterator it = ls.begin();it != ls.end();it++){
        cout << *(it) << " ";
    }
    cout << "\n";
    // rest functions are same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

    // Deque : 
    cout << "Deque : " << endl;

    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2); // {1, 2}
    dq.push_front(3); // {3, 1, 2}
    dq.emplace_front(4); // {4, 3, 1, 2}

    dq.pop_back(); // {4, 3, 1}
    dq.pop_front(); // {3, 1}

    cout << dq.back() << endl;
    cout << dq.front() << endl;

    cout << dq[1] << endl;

    // rest functions same as vector 
    // begin, end, rbegin, rend, clear, insert, size, swap


    // Stack
    cout << "Stack : " << endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(3);
    s.emplace(5);// {5, 3, 3, 2, 1}

    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;

    stack<int> s1;
    s1.swap(s);


    // Queue
    cout << "Queue : " << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);
    
    q.back() += 5;
    cout << q.back() << endl;// {1, 2, 9}
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl; // {2, 9}
    // else swap is same as stack

    // Priority Queue
    cout << "Priority Queue : " << endl;
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top() << endl; // 10
    pq.pop();
    cout << pq.top() << endl; // 8

    // size swap and empty functions are same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10); // {2, 5, 8, 10}

    cout << pq1.top() << endl;

    // Set 
    cout << "Set : " << endl;
    set<int> st;
    st.insert(1);
    st.insert(2); // {1, 2} in sorted fashion
    st.insert(2); // {1, 2} no duplicates allowed
    st.insert(4); // {1, 2, 4}
    st.emplace(3); // {1, 2, 3, 4}

    // Functionality of insert in can be used also, that
    // only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), 
    // empty(), and swap(), are same as those of above

    // {1, 2, 3, 4, 5}
    auto its1 = st.find(3);

    // {1, 2, 3, 4, 5}
    auto its2 = st.find(6);

    // {1, 4, 5}
    st.erase(5); // erases 5 // takes logarithmic time

    auto its3 = st.find(3);
    st.erase(its3); // it takes constant time

    // {1, 2, 3, 4, 5}
    auto its4 = st.find(2);
    auto its5 = st.find(4);
    st.erase(its4, its5); // after erase {1, 4, 5} [first, last)    
    
    // lower_bound() and upper_bound() function works in the same way 
    // as in vector it does

    // This is the syntax
    auto its6 = st.lower_bound(2);

    auto its7 = st.upper_bound(3);

    // MultiSet
    cout << "Multiset : " << endl;

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1};
    ms.insert(1); // {1, 1, 1}

    // ms.erase(1); // all 1's erased;

    int cnt1 = ms.count(1);
    cout << cnt1 << endl;

    // only a single one erased
    ms.erase(ms.find(1));
    auto itms1 = ms.find(1); 
    // ms.erase(itms1, ms.end());

    // rest all functions are same as set

    // Unordered_set
    cout << "Unordered_set : " << endl;
    unordered_set<int> ust;

    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above, it does not store in any particular
    // order, It has a better time complexity than set 
    // in most of the cases, except some when collision happens

    // Map 
    cout << "Map : " << endl;

    map<int, int> mpp;

    map<int, pair<int, int> > mpp1;

    map<pair<int, int>, int> mpp2;

    // key values can be everything

    mpp[1] = 2;
    mpp.emplace(3, 1);

    mpp.insert({2, 4});
    mpp.insert({1, 7});
    mpp1.insert({1,{1, 2}});
    // {
    //     {1, 2}
    //     {2, 4}
    //     {3, 1}
    // }

    for(auto it : mpp){
        cout << it.first << " " << it.second << endl;
    }
    // cout << mpp1[1].first << " " << mpp1[1].second << endl;
    

    cout << mpp[4] << endl; // prints 0, since it does not exists
    // same options for using iterators 
    // as we did vector for the insert function

    auto itm1 = mpp.find(2); // points to the position where 2 is found
    cout << (*(itm1)).second << endl;

    // lower_bound and upper_bound works exactly 
    // in same way as explained in the other video. 

    // This is the syntax
    auto itm2 = mpp.lower_bound(2);
    auto itm3 = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above.


    // Multimap 
    cout << "Multimap : " << endl;
    // Multimap allows duplicate key - value pairs as well as same key can have
    // multiple values. They are always stored in a sorted fashion.

    multimap<int, int> mmp;
    mmp.insert({1, 2});
    mmp.insert({1,2});
    mmp.insert({1, 3});

    for(auto it : mmp){
        cout << it.first << " " << it.second << endl;
    }

    // Unordered Map 
    cout << "Unordered Map : " << endl;
    // Unordered map is same as map but here the elements are stored
    // randomly.
    // But in this you may face collisions which may produce runtime error.
    // or a Time Limit Exceeded.

    // Extra Information

    // sort(a, a + 4); // [first, last)
    // sort(a, a + 4, greater<int>);

    // pair<int, int> a1[] = {{1, 2}, {3, 4}, {5, 6}};

    // sort(a, a + 7, comp);
    // comparator function
    // bool comp(pair<int, int> p1, pair<int, int> p2){
    //     if(p1.second < p2.second){
    //         return true;
    //     }
    //     if(p1.second == p2.second){
    //         if(p1.first > p2.first){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    int num = 7; // 111
    int cnt = __builtin_popcount(num);

    long long int num1 = 10397157987459;
    int count2 = __builtin_popcountll(num1);

   // count the no. of Set bits 
    cout << cnt << " " << count2 << endl;

    string s12 = "123";
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(2);
    sort(v1.begin(), v1.end());
    do{
        for(auto it : v1){
            cout << it << " ";
        }
        cout << endl;
    }while(next_permutation(v1.begin(), v1.end()));

    // 123
    // 132
    // 213
    // 231
    // 312
    // 321

    // Max element in a container
    int a2[] = {3, 5, 28, 76, 100, 86, 128};
    int n = (*(&a2 + 1) - a2);
    int max = *min_element(a2, a2+n);
    cout << max << " " << n << endl;

    return 0;
}





// Vector  List
// It has contiguous memory.   While it has non-contiguous memory.
// It is synchronized. While it is not synchronized.
// Vector may have a default size. List does not have default size.
// In vector, each element only requires the space for itself only.    In list, each element requires extra space for the node which holds the element, including pointers to the next and previous elements in the list.
// Insertion at the end requires constant time but insertion elsewhere is costly.  Insertion is cheap no matter where in the list it occurs.
// Vector is thread safe.  List is not thread safe.
// Deletion at the end of the vector needs constant time but for the rest it is O(n).  Deletion is cheap no matter where in the list it occurs.
// Random access of elements is possible.  Random access of elements is not possible.
// Iterators become invalid if elements are added to or removed from the vector.   Iterators are valid if elements are added to or removed from the list.