#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
    }
};

Node *createTree()
{
    Node *root = NULL;
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    // cout << "How many subtrees do you want : ";
    // int subtrees;
    // cin >> subtrees;
    // for(int i = 0;i < subtrees;i++){
    //     cout << "Enter data for " << i + 1 << " child of " << data << endl;
    //     int child;
    //     cin >> child;
    //     root-> = createTree();
    // }
    // Creating a Left Subtree
    cout << "Enter the left child for " << data << " : " << endl;
    root->left = createTree();
    // Creating a right Subtree
    cout << "Enter the right child for " << data << " : " << endl;
    root->right = createTree();
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    // While there is atleast one discovered node
    int level = 0;
    cout << "Level " << level << " = ";
    while (!q.empty())
    {
        Node *current = q.front();
        if (current == NULL)
        {
            cout << endl;
            q.pop();
            if (q.empty())
            {
                break;
            }
            level++;
            cout << "Level " << level << " = ";
            q.push(NULL);
            continue;
        }
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop(); // removing the element at the front.
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
    return;
}

void levelOrder(Node *root, int level, vector<vector<int>> &arr)
{
    if (root == NULL)
    {
        return;
    }
    arr[level].push_back(root->data);
    levelOrder(root->left, level + 1, arr);
    levelOrder(root->right, level + 1, arr);
    return;
}

int main()
{
    Node *root = createTree();
    cout << "PreOrder Traversal : " << endl;
    preOrder(root);
    cout << endl;

    cout << "PostOrder traversal : " << endl;
    postOrder(root);
    cout << endl;

    cout << "InOrder Traversal : " << endl;
    inOrder(root);
    cout << endl;

    // Brute force for Level - Order Traversal
    cout << "Brute Force Level Order Traversal" << endl;
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printLevel(root, i);
    }
    cout << endl;

    cout << "Level Order Traversal Using Queue : " << endl;
    LevelOrder(root);
    cout << endl;

    vector<vector<int>> arr(height(root), vector<int>());
    cout << "Level Order  Using 2d array : " << endl;
    levelOrder(root, 0, arr);
    for (int i = 0; i <= height(root); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}