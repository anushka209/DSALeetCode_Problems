class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || vis[i][j])
            return;
        vis[i][j]=true;  //mark visited

        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
    }

    int numberOfIslands(vector<vector<int>>& grid)
    {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])  // land
                {
                    dfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=numberOfIslands(grid);
        if(island==0 || island>1)  
            return 0;
        else     // we have only one island check if we can disconnect the grid in one day
        {
           for(int i=0;i<n;i++)
           {
             for(int j=0;j<m;j++)
             {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;   //convert into water

                island=numberOfIslands(grid);
                if(island==0 || island>1)
                    return 1;
                grid[i][j]=1;    //make it land again and now got to try next cell
              }
             }
           }
        }
        return 2;
    }
};