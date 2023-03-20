class Solution
{
public:
    // Whenever we get a matrix and in it, we are asked to find minimum distance between something,
    // our idea must straight go to applying bfs.

    // In bfs, if we have multiple starting points, apply multi-source bfs.

    // In bfs in general, we have to form a queue store the starting points,
    // and the initial distance which is 0 in this case.

    // Also, we require an visited array for the coordinates visited till now.

    // In this case, if we reach the desired point at first that will be our answer,
    // that is minimum distance to reach the destination point early.

    // As soon as the first 'Y' is encountered, that was the most closest 'Y' to an 'X' and thus
    // our answer so we break the loop and return the answer.

    int shortestXYDist(vector<vector<char>> grid, int N, int M)
    {
        // code here
        
        // Brute Force : TLE.
        // vector<pair<int,int>>x,y;
        // for(int i = 0 ; i < N ; i++)
        // {
        //     for(int j = 0 ; j < M ; j++)
        //     {
        //         if(grid[i][j] =='X')
        //         {
        //             x.push_back({i,j});
        //         }
        //         else if(grid[i][j] == 'Y')
        //         {
        //             y.push_back({i,j});
        //         }
        //     }
        // }
        // int ans = 1e9;
        // for(auto &e:x)
        // {
        //     for(auto &r:y)
        //     {
        //         ans = min(ans,abs(e.first-r.first) + abs(e.second - r.second));
        //     }
        // }
        // return ans;
        
        // // DP.
        
        // // At start, every cell is unreachable, so we denote it with a big value, 1e9.
        // // Then the distance between x and x is 0. So we update that.
        // vector<vector<int>> minDist(n, vector<int>(m, 1e9));
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(grid[i][j] == 'X'){
        //             minDist[i][j] = 0;
        //         }
        //     }
        // }
        
        // // Now for every cell we try to find the closest X for it.
        // // Our possible movements are :- 1) up, down, left, right.
        // // So the minimum of four of them will give us the answer.
        
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
                
        //         // As we are iterating from start, and from left to right.
        //         // Two directions aren't computed yet.
        //         // down and right so ignore them.
        //         // Up
        //         if(i - 1 >= 0){
        //             minDist[i][j] = min(minDist[i][j], 1 + minDist[i - 1][j]);
        //         }
        //         // left
        //         if(j - 1 >= 0){
        //             minDist[i][j] = min(minDist[i][j], 1 + minDist[i][j - 1]);
        //         }
        //     }
        // }
        
        // // In some cases x is after y, so it won't get updated for y's coordinates, therefore,
        // // we need to iterate in backward direction as well.
        
        // for(int i = n - 1;i >= 0;i--){
        //     for(int j = m - 1;j >= 0;j--){
        //         // Now here the directions for which we haven't computed anything is, 
        //         // up and left.
                
        //         // Bottom 
        //         if(i + 1 < n){
        //             minDist[i][j] = min(minDist[i][j], minDist[i + 1][j] + 1);
        //         }
        //         // right;
        //         if(j + 1 < m){
        //             minDist[i][j] = min(minDist[i][j], minDist[i][j + 1] + 1);
        //         }
        //     }
        // }
        
        // // At the end check for all positions of y, and store the minimum as the answer.
        // int ans = 1e9;
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(grid[i][j] == 'Y'){
        //             ans = min(ans, minDist[i][j]);
        //         }
        //     }
        // }
        
        // return ans;
        
        
        // BFS
        // element -> {{coordinates}, distance}.
        // queue<pair<pair<int, int>, int>> q;
        // // We will also require a visited array in bfs.
        // vector<vector<int>> visited(n, vector<int>(m, 0));

        // // We will take all the starting points and push it into the queue.
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (grid[i][j] == 'X')
        //         {
        //             q.push({{i, j}, 0});
        //             visited[i][j] = 1;
        //         }
        //     }
        // }

        // int ans = 0;

        // vector<int> dr = {0, 0, 1, -1};
        // vector<int> dc = {1, -1, 0, 0};

        // while (!q.empty())
        // {
        //     auto curr = q.front();
        //     q.pop();

        //     int i = (curr.first).first;
        //     int j = (curr.first).second;

        //     int dis = curr.second;

        //     if (grid[i][j] == 'Y')
        //     {
        //         ans = dis;
        //         break;
        //     }

        //     for (int k = 0; k < 4; k++)
        //     {
        //         int di = i + dr[k];
        //         int dj = j + dc[k];

        //         if (di >= 0 && di < n && dj >= 0 && dj < m && !visited[di][dj])
        //         {
        //             q.push({{di, dj}, dis + 1});
        //             visited[di][dj] = 1;
        //         }
        //     }
        // }

        // return ans;
    }
};