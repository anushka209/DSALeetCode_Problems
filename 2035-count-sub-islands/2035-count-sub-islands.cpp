class Solution {
public:
    int n,m;
    bool flag;
    bool vis[510][510];
    vector<vector<int>>gridi,gridii;

    void dfs(int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || !gridii[i][j] || vis[i][j])
            return;
        vis[i][j]=true;
        if(!gridi[i][j])
            flag=false;
        
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i-1,j);
        dfs(i,j-1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        gridi=grid1,gridii=grid2;
        n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && gridii[i][j])
                {
                    flag=true;
                    dfs(i,j);
                    ans+=flag;
                }
            }
        }
        return ans;
    }
};