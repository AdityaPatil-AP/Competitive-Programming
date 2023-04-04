class Solution
{

public:
    int xmod11(string x)
    {
        // code here
        int a = 0;
        for (auto &num : x)
        {
            a = (a * 10 + (num - '0')) % 11;
        }

        return a;
    }
};
