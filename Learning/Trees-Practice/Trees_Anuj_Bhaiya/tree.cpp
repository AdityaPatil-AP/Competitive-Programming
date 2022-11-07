#include <iostream>
using namespace std;

// You can make generic class.
template <typename T>
class Node
{
public:
    Node *left, *right;
    T data;

public:
    Node(T data)
    {
        this->data = data;
    }
};

template <typename T>
Node<T> *createTree()
{
    Node<T> *root = NULL;
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Node<T>(data);
    cout << "Enter left Child data for " << data << " : " << endl;
    root->left = createTree<T>();
    cout << "Enter right Child data for " << data << " : " << endl;
    root->right = createTree<T>();
    return root;
}

int main()
{
    // Creation of a Tree.
    Node<int> *root = createTree<int>();

    // Printing a Tree.
    return 0;
}