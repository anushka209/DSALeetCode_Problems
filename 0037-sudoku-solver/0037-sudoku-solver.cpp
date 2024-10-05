class Solution {
public:
    bool isvalid(int row,int col,char c,vector<vector<char>>& board)
    {
       for(int i=0;i<9;i++)
       {
        if(board[row][i]==c)    return false;
        if(board[i][col]==c)    return false;
        if(board[3*(row/3)+ i/3][3*(col/3)+ i%3]==c) return false;
       }
       return true;
    }

    bool find(vector<vector<char>> &board)
    {
       for(int i=0;i<board.size();i++)
       {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
                for(char ch='1';ch<='9';ch++)
                {
                    if(isvalid(i,j,ch,board)==true)
                     {
                        board[i][j]=ch;
                        if(find(board)==true)
                            return true;
                        else
                            board[i][j]='.';   //backtrack
                     }
                }
                return false;
            }
        }
       }
       return true;      //completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        find(board);
    }
};