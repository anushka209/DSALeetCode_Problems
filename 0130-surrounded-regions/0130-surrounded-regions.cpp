class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>>& board,int dr[],int dc[])
    {
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1; 
        //check for top bottom left right
        for(int i=0;i<4;i++)
        {
            int newR=r+dr[i];
            int newC=c+dc[i];
            if(newR>=0 && newR<n && newC>=0 && newC<m && board[newR][newC]=='O' && !vis[newR][newC])
                dfs(newR,newC,vis,board,dr,dc);
        } 
    }

    void solve(vector<vector<char>>& board) {
       int m=board.size();
       int n=board[0].size();
       vector<vector<int>>vis(m,vector<int>(n,0));
       int dr[]={-1,0,+1,0};
       int dc[]={0,+1,0,-1};
       for(int j=0;j<n;j++)     // first row & last row
       {
          if(!vis[0][j] && board[0][j]=='O')      //first row
            dfs(0,j,vis,board,dr,dc);
          if(!vis[m-1][j] && board[m-1][j]=='O')   //last row
            dfs(m-1,j,vis,board,dr,dc);
       }
       for(int i=0;i<m;i++)     // first column & last column
       {
          if(!vis[i][0] && board[i][0]=='O')      //first row
            dfs(i,0,vis,board,dr,dc);
          if(!vis[i][n-1] && board[i][n-1]=='O')   //last row
            dfs(i,n-1,vis,board,dr,dc);
       }
       for(int i=0;i<m;i++)         //convert O to X as it is not lie on the edge
       {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
        }
       }
    }
};