class Solution
{
public:
    int partitionString(string s)
    {
        set<char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) == st.end() || st.size() == 0)
            {
                st.insert(s[i]);
            }
            else
            {
                cnt++;
                st.erase(st.begin(), st.end());
                i--;
            }
        }
        if (st.size() != 0)
        {
            cnt++;
        }
        return cnt;
    }
};