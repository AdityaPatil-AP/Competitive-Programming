class Solution
{
public:
    int maxDifferenceBST(Node *root, int target)
    {
        // Code here
        int sum = 0;

        Node *curr = root;

        // Finding the target Node.
        while (curr != NULL)
        {
            if (curr->data > target)
            {
                sum += curr->data;
                curr = curr->left;
            }
            else if (curr->data < target)
            {
                sum += curr->data;
                curr = curr->right;
            }
            else
            {
                break;
            }
        }

        // If the target is not found.
        if (curr == NULL)
        {
            return -1;
        }

        // Finding the minimum path in the lower-half.
        // If target node is leaf node.
        if (curr->left == NULL && curr->right == NULL)
        {
            return sum;
        }

        // Now we have to cover every path and check the minimum path sum from the curr node.
        int minsum = INT_MAX;
        if (curr->left)
        {
            minsum = minPathSum(curr->left);
        }
        if (curr->right)
        {
            minsum = min(minsum, minPathSum(curr->right));
        }

        return (sum - minsum);
    }

    int minPathSum(Node *root)
    {
        // we have to stop at the root node.
        if (root->left == NULL && root->right == NULL)
            return root->data;

        int path1 = INT_MAX, path2 = INT_MAX;

        if (root->left)
        {
            path1 = min(path1, root->data + minPathSum(root->left));
        }

        if (root->right)
        {
            path2 = min(path2, root->data + minPathSum(root->right));
        }

        return min(path1, path2);
    }
};