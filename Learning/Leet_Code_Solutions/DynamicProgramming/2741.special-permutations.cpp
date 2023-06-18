class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[15][15][20000];

    int countPermutations(int index, int prevIndex, vector<int> &nums, int mask)
    {
        if (index == (nums.size()))
        {
            return 1;
        }

        if (dp[index][prevIndex][mask] != -1)
        {
            return dp[index][prevIndex][mask];
        }

        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < 14 && i < nums.size(); i++)
        {
            if ((mask >> i) & 1)
            {
                continue;
            }

            if (prevIndex == 0)
            {
                int new_mask = (mask | (1 << i));
                ans = (ans + countPermutations(index + 1, i + 1, nums, new_mask)) % mod;
            }
            else
            {
                int prevVal = nums[prevIndex - 1];
                int currVal = nums[i];
                int new_mask = (mask | (1 << (i)));
                if ((prevVal % currVal == 0) || (currVal % prevVal == 0))
                {
                    ans = (ans + countPermutations(index + 1, i + 1, nums, new_mask)) % mod;
                }
            }
        }

        return dp[index][prevIndex][mask] = ans % mod;
    }

    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        int count = countPermutations(0, 0, nums, 0);

        return count % mod;
    }
};