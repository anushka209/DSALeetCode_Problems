class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int>source;
        pair<int,int>destination;
        source.first=0;
        source.second=0;
        destination.first=n-1;
        destination.second=n-1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)  return -1;
        if(n==1) return 1;
       if(source.first==destination.first && source.second==destination.second)
            return 0;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[source.first][source.second]=1;
        q.push({1,{source.first,source.second}});
        
        int dr[]={-1,-1,0,+1,+1,+1,0,-1};
        int dc[]={0,+1,+1,+1,0,-1,-1,-1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++)
            {
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dis+1<dist[newr][newc])
                {
                    dist[newr][newc]=dis+1;
                    if(newr==destination.first && newc==destination.second)
                        return dis+1;
                    q.push({1+dis,{newr,newc}});
                }
            }
        }
        return -1;
    }
};