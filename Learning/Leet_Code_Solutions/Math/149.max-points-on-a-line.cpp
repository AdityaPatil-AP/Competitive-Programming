class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int maxi = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                else
                {
                    double m = ((double)points[i][0] - points[j][0]) / ((double)(points[i][1] - points[j][1]));
                    mp[m]++;
                }
            }
            for (auto m : mp)
            {
                maxi = max(maxi, m.second);
            }
            mp.clear();
        }
        return maxi + 1;
    }
};