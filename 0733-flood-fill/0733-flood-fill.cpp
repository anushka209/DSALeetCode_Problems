class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int dr[],int dc[],vector<vector<int>>& ans,int iniCol)
    {
        ans[sr][sc]=color;
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++)        //becoz we have to move in 4 directions
        {
            int newr=sr+dr[i];
            int newc=sc+dc[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && image[newr][newc]==iniCol && ans[newr][newc]!=color)
                dfs(newr,newc,image,color,dr,dc,ans,iniCol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol=image[sr][sc];
        vector<vector<int>>ans=image;        //copy the data given
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        dfs(sr,sc,image,color,dr,dc,ans,iniCol);
        return ans;
    }
};