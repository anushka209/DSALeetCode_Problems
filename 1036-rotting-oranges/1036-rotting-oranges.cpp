class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       // {{r,c},t}
       queue<pair<pair<int,int>,int>>q;
       vector<vector<int>>vis(m,vector<int>(n,0));
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
         {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=2;
            }
         }
       }
       int dr[]={-1,0,+1,0};    // four directions
       int dc[]={0,+1,0,-1};
       int time=0;    
       while(!q.empty())     //bfs
       {
         int row=q.front().first.first;
         int col=q.front().first.second;
         int t=q.front().second;
         time=max(time,t);
         q.pop();
         for(int i=0;i<4;i++)
         {
            int newr=row+dr[i];
            int newc=col+dc[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0 && grid[newr][newc]==1)
            {
                q.push({{newr,newc},t+1});
                vis[newr][newc]=2;
            }
         }
       } 
     for(int i=0;i<m;i++)        //finally check at end
     {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]!=2 && grid[i][j]==1)
                return -1;
        }
     }
     return time;
    }
};


      