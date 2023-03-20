class Solution
{
public:
    vector<int> getDistinctDifference(int N, vector<int> &A)
    {
        // code here
        // prev -> will store all the prev elements to i.
        // future -> will store all the future elements right to i.

        map<int, int> prev;
        map<int, int> future;

        for (auto it : A)
        {
            future[it]++;
        }

        vector<int> ans;

        for (int i = 0; i < N; i++)
        {
            future[A[i]]--;
            if (future[A[i]] == 0)
            {
                future.erase(A[i]);
            }

            ans.push_back((prev.size() - future.size()));

            prev[A[i]]++;
        }

        return ans;
    }
};