class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
        // int n = s.size();
        // unordered_map<int, vector<int>> avail;
        // for (int i = 0; i < n; ++i) {
        //     if (s[i] == '1') {
        //         int v = 0;
        //         for (int j = i; j < min(n, i+30); ++j) {
        //             v *= 2;
        //             if (s[j] == '1') ++v;
        //             if (!avail.count(v)) avail[v] = {i, j};
        //         }
        //     } else if (!avail.count(0)) avail[0] = {i, i};
        // }
        // vector<vector<int>> ans;
        // for (auto& q : queries) {
        //     int v = q[0] ^ q[1];
        //     if (avail.count(v)) ans.push_back(avail[v]);
        //     else ans.push_back({-1, -1});
        // }
        // return ans;

        // Leader Solution.
        int n = s.size();

        unordered_map<int, vector<int>> avail;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                int val = 0;
                for (int j = i; j < min(n, i + 31); j++)
                {
                    val *= 2;
                    if (s[j] == '1')
                        ++val;
                    if (!avail.count(val))
                        avail[val] = {i, j};
                }
            }
            else if (!avail.count(0))
                avail[0] = {i, i};
        }

        vector<vector<int>> ans;
        for (auto &q : queries)
        {
            int v = q[0] ^ q[1];
            if (avail.count(v))
                ans.push_back(avail[v]);
            else
                ans.push_back({-1, -1});
        }

        return ans;
    }
};