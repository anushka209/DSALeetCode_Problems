class Solution {
public:
    void place_queen(int col,int n,vector<string> &board,vector<vector<string>> &ans,vector<int> &left_row,vector<int> &upper_diagonal,vector<int> &lower_diagonal)
    {
       if(col==n)
       {
          ans.push_back(board);
          return;
       }
        for(int row=0;row<n;row++)      //iterate in every row
        {
            if(left_row[row]==0 && upper_diagonal[n-1+col-row]==0 && lower_diagonal[row+col]==0)
            {
                board[row][col]='Q';
                left_row[row]=1;
                upper_diagonal[n-1+col-row]=1;
                lower_diagonal[row+col]=1;
                place_queen(col+1,n,board,ans,left_row,upper_diagonal,lower_diagonal);
                board[row][col]='.';   //backtrack
                left_row[row]=0;
                upper_diagonal[n-1+col-row]=0;
                lower_diagonal[row+col]=0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>board(n);
      string s(n,'.');
      for(int i=0;i<n;i++)
      {
        board[i]=s;
      }
      vector<int>left_row(n,0),lower_diagonal(2*n-1,0),upper_diagonal(2*n-1,0);
      place_queen(0,n,board,ans,left_row,upper_diagonal,lower_diagonal);
      return ans;
    }
};