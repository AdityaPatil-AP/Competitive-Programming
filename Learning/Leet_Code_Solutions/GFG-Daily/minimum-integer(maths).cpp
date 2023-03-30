class Solution
{
public:
    int minimumInteger(int N, vector<int> &A)
    {
        // code here
        long long sum;
        sum = accumulate(A.begin(), A.end(), 0ll);
        long long ans = 1e9 + 1;
        for (int i = 0; i < N; i++)
        {
            if ((long long)N * (long long)A[i] >= sum)
            {
                ans = min(ans, (long long)A[i]);
            }
        }

        return ans;
    }
};