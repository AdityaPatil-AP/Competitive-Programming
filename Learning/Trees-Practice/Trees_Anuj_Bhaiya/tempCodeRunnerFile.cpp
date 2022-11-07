#include <iostream>
using namespace std;

// You can make generic class.
template <typename T>
class Node
{
    Node *left, *right;
    T data;

public:
    Node(T data)
    {
        this.data = data;
    }