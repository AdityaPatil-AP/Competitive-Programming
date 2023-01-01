class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> mp;
        vector<string> strs;
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                word.push_back(s[i]);
            }
            else
            {
                strs.push_back(word);
                word = "";
            }
        }
        strs.push_back(word);
        set<string> st;
        if (pattern.size() != strs.size())
            return false;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) != mp.end())
            {
                if (mp[pattern[i]] == strs[i])
                {
                    continue;
                }
                else
                    return false;
            }
            else
            {
                if (st.find(strs[i]) != st.end())
                {
                    return false;
                }
                mp[pattern[i]] = strs[i];
                st.insert(strs[i]);
            }
        }
        return true;
    }
};