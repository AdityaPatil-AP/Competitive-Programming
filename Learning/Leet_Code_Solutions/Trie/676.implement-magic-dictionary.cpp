// Using UnorderedMap.

class MagicDictionary
{
public:
    unordered_map<int, vector<string>> mp;
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dict)
    {
        for (auto str : dict)
        {
            mp[str.size()].push_back(str);
        }
    }

    bool found(string &str, string &searchWord)
    {
        int diff = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != searchWord[i])
                diff++;
        }
        return (diff == 1);
    }

    bool search(string searchWord)
    {
        int n = searchWord.size();
        for (auto str : mp[n])
        {
            if (found(str, searchWord))
            {
                return true;
            }
        }
        return false;
    }
};