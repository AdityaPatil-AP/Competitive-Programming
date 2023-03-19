

// Using recursion.

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // ending point (n/2, m/2);
        int n = matrix.size();
        int m = matrix[0].size();
        return order(matrix, 0, 0, n - 1, m - 1);
    }

    vector<int> order(vector<vector<int>> &matrix, int starti, int startj, int endi, int endj)
    {
        if (starti > endi || startj > endj)
        {
            return {};
        }
        if (starti == endi)
        {
            vector<int> curr;
            for (int i = startj; i <= endj; i++)
            {
                curr.push_back(matrix[starti][i]);
            }
            return curr;
        }

        vector<int> smallans = order(matrix, starti + 1, startj + 1, endi - 1, endj - 1);

        vector<int> ans;
        // for the top row.
        for (int i = startj; i <= endj; i++)
            ans.push_back(matrix[starti][i]);

        for (int i = starti + 1; i <= endi; i++)
            ans.push_back(matrix[i][endj]);

        for (int i = endj - 1; i >= startj; i--)
            ans.push_back(matrix[endi][i]);

        if (startj != endj)
            for (int i = endi - 1; i >= starti + 1; i--)
                ans.push_back(matrix[i][startj]);

        for (auto it : smallans)
        {
            ans.push_back(it);
        }

        return ans;
    }
};