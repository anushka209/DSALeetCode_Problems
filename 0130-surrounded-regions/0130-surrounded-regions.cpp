class Solution {
public:
    void dfs(int r,int c,vector<vector<char>> &board,vector<vector<int>>& vis,int dr[],int dc[])
    {
        vis[r][c]=1;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<4;i++)      //check for top bottom left right
        {
            int newr=r+dr[i];
            int newc=c+dc[i];
            if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]==0 && board[newr][newc]=='O')
                dfs(newr,newc,board,vis,dr,dc);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        for(int j=0;j<n;j++)           // first row & last row
        {
            if(vis[0][j]==0 && board[0][j]=='O')     // first row
                dfs(0,j,board,vis,dr,dc);
            if(vis[m-1][j]==0 && board[m-1][j]=='O')  // last row
                dfs(m-1,j,board,vis,dr,dc);
        }
        for(int i=0;i<m;i++)          // first column & last column
        {
            if(vis[i][0]==0 && board[i][0]=='O')      // first column
                dfs(i,0,board,vis,dr,dc);
            if(vis[i][n-1]==0 && board[i][n-1]=='O')  // last column 
                dfs(i,n-1,board,vis,dr,dc);
        }
        for(int i=0;i<m;i++)       // convert O to X as it is not lie on the edge
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};