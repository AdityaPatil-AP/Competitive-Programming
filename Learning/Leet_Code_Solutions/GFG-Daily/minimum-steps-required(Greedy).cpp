int minSteps(string s)
{
    // Write your code here.

    int ans = 0;
    int n = s.size();

    int counta = 0;
    int countb = 0;
    char curr = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == curr)
        {
            continue;
        }
        else
        {
            if (s[i - 1] == 'b')
                countb++;
            else
                counta++;

            curr = s[i];
        }
    }

    if (s[n - 1] == 'b')
        countb++;
    else
        counta++;

    if (counta > 0 && countb > 0)
        ans = 1 + min(counta, countb);
    else
        ans = 1;

    return ans;
}