class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;         //row,col,distance
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else
                    vis[i][j]=0;
            }
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty())     //using bfs
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            dist[row][col]=distance;
            for(int i=0;i<4;i++)
            {
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0)
                {
                    vis[newr][newc]=1;
                    q.push({{newr,newc},distance+1});
                }
            }
        }
        return dist;
    }
};
