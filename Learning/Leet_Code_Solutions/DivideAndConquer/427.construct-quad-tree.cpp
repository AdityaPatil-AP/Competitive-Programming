/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return helper(0, 0, n, grid);
    }

    Node *helper(int x1, int y1, int length, vector<vector<int>> &grid)
    {

        // If all the values are equal in subgrid, then it is a leaf node.
        if (checkEqual(x1, y1, length, grid))
        {
            return new Node(grid[x1][y1], true);
        }

        // If it is not a leaf node, then we must have four children for it.
        // Four different calls
        else
        {
            Node *ans = new Node(false, false);
            ans->topLeft = helper(x1, y1, length / 2, grid);
            ans->topRight = helper(x1, y1 + length / 2, length / 2, grid);
            ans->bottomLeft = helper(x1 + length / 2, y1, length / 2, grid);
            ans->bottomRight = helper(x1 + length / 2, y1 + length / 2, length / 2, grid);

            return ans;
        }
    }

    bool checkEqual(int x1, int y1, int length, vector<vector<int>> &grid)
    {
        int num = grid[x1][y1];
        for (int i = x1; i < x1 + length; i++)
        {
            for (int j = y1; j < y1 + length; j++)
            {
                if (num != grid[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};