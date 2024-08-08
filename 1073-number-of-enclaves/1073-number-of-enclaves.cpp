class Solution {
public:
    // void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,int dr[],int dc[])   //dfs
    // {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vis[r][c]=1;
    //     for(int i=0;i<4;i++)
    //     {
    //         int row=r+dr[i];
    //         int col=c+dc[i];
    //         if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1)
    //             dfs(row,col,vis,grid,dr,dc);
    //     }
    // }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();            //same for both bfs and dfs
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
       
        queue<pair<int,int>>q;
       // we can also use this in place of all 4 boundary traversals ie.
            // first row, first col, last row, last col 
           // if(i == 0 || j == 0 || i == n-1 || j == m-1)

        // for(int j=0;j<m;j++)   //for ist row     //dfs code
        // {
        //     if(grid[0][j]==1 && !vis[0][j])
        //         dfs(0,j,vis,grid,dr,dc);
        // }

        //  for(int j=0;j<m;j++)   //for last row
        // {
        //     if(grid[n-1][j]==1 && !vis[n-1][j])
        //         dfs(n-1,j,vis,grid,dr,dc);
        // }

        //  for(int i=0;i<n;i++)   //for ist col
        // {
        //     if(grid[i][0]==1 && !vis[i][0])
        //         dfs(i,0,vis,grid,dr,dc);
        // }

        // for(int i=0;i<n;i++)   //for last col
        // {
        //     if(grid[i][m-1]==1 && !vis[i][m-1])
        //         dfs(i,m-1,vis,grid,dr,dc);
        // }

        // int count = 0;
        // for(int i = 0;i<n;i++) {
        //     for(int j = 0;j<m;j++) {
        //             // check for unvisited land cell
        //         if(grid[i][j] == 1 & vis[i][j] == 0) 
        //             count++; 
        //     }
        // }
        // return count;

        for(int i=0;i<n;i++)              //bfs
        {
            for(int j=0;j<m;j++)
            {
                // first row, first col, last row, last col 
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                            q.push({i,j});
                            vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=row+dr[i];
                int c=col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]==0)
                {
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    count++;
            }
        }
        return count;
    }
};