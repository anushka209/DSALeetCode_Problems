class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int dr[],int dc[],int iniCol)
    {
        ans[r][c]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)     //becoz we have to move in 4 directions
        {
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==iniCol && ans[row][col]!=color)
                dfs(row,col,image,ans,color,dr,dc,iniCol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int iniCol=image[sr][sc];
       vector<vector<int>>ans=image;  //copy the data given
       int dr[]={-1,0,+1,0};
       int dc[]={0,+1,0,-1};
       dfs(sr,sc,image,ans,color,dr,dc,iniCol);
       return ans;
    }
};