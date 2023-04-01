class Solution
{
public:
    long long int minOperations(int n)
    {
        // Code here
        // odd
        if (n % 2 == 1)
        {
            long long m = n / 2;

            return (2ll * (m * (m + 1)) / 2);
        }

        return ((((long long)n / 2)) * (long long)n) / 2ll;
    }
};