class Solution
{
public:
    void dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited)
    {
        set<int> st;
        for (auto neighbour : graph[node])
        {
            st.insert(visited[neighbour - 1]);
        }
        for (int i = 1; i <= 4; i++)
        {
            if (st.find(i) == st.end())
            {
                visited[node - 1] = i;
                break;
            }
        }
        return;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        // Creation of Adjacency list.

        unordered_map<int, vector<int>> graph;
        for (auto path : paths)
        {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }

        vector<int> visited(n, 0);
        // It may happen that it may have more than one connected component.
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i - 1])
            {
                dfs(i, graph, visited);
            }
        }

        return visited;
    }
};