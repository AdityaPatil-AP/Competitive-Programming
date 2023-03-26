class Solution
{
public:
    int unvisitedLeaves(int N, int leaves, int frogs[])
    {
        // Code here

        // Us
        vector<bool> arr(leaves + 1, true);

        sort(frogs, frogs + N);

        for (int i = 0; i < N; i++)
        {
            int jumpSize = frogs[i];
            if (frogs[i] <= leaves && arr[frogs[i]] == false)
            {
                continue;
            }
            else
            {
                for (int j = frogs[i]; j <= leaves; j += frogs[i])
                {
                    arr[j] = false;
                }
            }
        }

        int cnt = 0;

        // arr[i] == true, tell the leaf is unvisited.
        for (int i = 1; i <= leaves; i++)
        {
            if (arr[i] == true)
            {
                cnt++;
            }
        }

        return cnt;
    }
};