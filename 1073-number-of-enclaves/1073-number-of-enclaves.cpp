class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,int dr[],int dc[])   //dfs
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int newr=r+dr[i];
            int newc=c+dc[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && !vis[newr][newc] && grid[newr][newc]==1)
                dfs(newr,newc,vis,grid,dr,dc);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();               //same for both bfs and dfs
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
       
       // queue<pair<int,int>>q;
       // we can also use this in place of all 4 boundary traversals ie.
            // first row, first col, last row, last col 
           // if(i == 0 || j == 0 || i == n-1 || j == m-1)

        for(int j=0;j<n;j++)      //for ist row & last row    //dfs code
        {
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,vis,grid,dr,dc);
            if(!vis[m-1][j] && grid[m-1][j]==1)
                dfs(m-1,j,vis,grid,dr,dc);
        }
        for(int i=0;i<m;i++)    // for ist col & last col
        {
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,vis,grid,dr,dc);
            if(!vis[i][n-1] && grid[i][n-1]==1)
                dfs(i,n-1,vis,grid,dr,dc);
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)      // check for unvisited land cell
                    count++;
            }
        }
        return count;

        // for(int i=0;i<n;i++)              //bfs
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         // first row, first col, last row, last col 
        //         if(i==0 || j==0 || i==n-1 || j==m-1)
        //         {
        //             if(grid[i][j]==1)
        //             {
        //                     q.push({i,j});
        //                     vis[i][j]=1;
        //             }
        //         }
        //     }
        // }
        // while(!q.empty())
        // {
        //     int row=q.front().first;
        //     int col=q.front().second;
        //     q.pop();
        //     for(int i=0;i<4;i++)
        //     {
        //         int r=row+dr[i];
        //         int c=col+dc[i];
        //         if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]==0)
        //         {
        //             q.push({r,c});
        //             vis[r][c]=1;
        //         }
        //     }
        // }
        // int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(grid[i][j]==1 && vis[i][j]==0)
        //             count++;
        //     }
        // }
        // return count;
    }
};