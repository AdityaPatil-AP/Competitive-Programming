class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &graph, const int &seats, long long &fuel)
    {
        // The node is representative itself.
        int r = 1;

        for (auto child : graph[node])
        {
            if (child != parent)
            {
                r += dfs(child, node, graph, seats, fuel);
            }
        }

        // if the node is not 0. then it need to transport the representatives to the parent node.
        // therefore add the fuel used by them to reach the parent node.
        if (node != 0)
        {
            fuel += ceil((double)r / seats);
        }

        return r;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        // Creation of adjacency list.
        long long fuel = 0;
        int n = roads.size();
        vector<vector<int>> graph(n + 1);

        for (auto road : roads)
        {
            int u = road[0];
            int v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Calling the dfs function with parameters.
        // 1) currnode 2) parent(to keep track of the parent of the currnode so that we don't go in opposite direction)
        // 3) graph 4) seats 5) fuelneeded.

        dfs(0, -1, graph, seats, fuel);

        return fuel;
    }
};