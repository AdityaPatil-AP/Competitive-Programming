class Solution
{
public:
    int appleSequences(int n, int m, string arr)
    {
        // code here
        // Sliding window.

        int i = 0, j = 0;
        int converted = 0;
        int ans = 0;

        while (j < arr.size())
        {
            if (arr[j] == 'O')
                converted++;

            if (converted <= m)
            {
                ans = max(ans, (j - i + 1));
            }
            else
            {
                while (converted > m)
                {
                    if (arr[i] == 'O')
                        converted--;
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};