class Solution {
public:
    bool find_next(int i,int j,int m,int n,int idx,vector<vector<char>>& board,string &word)
    {
        // if index reaches at the end that means we have found the word
         if(idx==word.size())
            return true;

     // Checking the boundaries if the character at which we are placed is not the required character
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$')
            return false;
        if(board[i][j]!=word[idx])
            return false;

     // this is to prevent reusing of the same character
        char temp=board[i][j];
        board[i][j]='$';

        bool top=find_next(i+1,j,m,n,idx+1,board,word);    // for top
        bool bottom=find_next(i-1,j,m,n,idx+1,board,word);   // for bottom
        bool left=find_next(i,j-1,m,n,idx+1,board,word);     // for left
        bool right=find_next(i,j+1,m,n,idx+1,board,word);    // right

        board[i][j]=temp;                  // undo change for backtracking
        return top || bottom || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
         // First search the first character
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && find_next(i,j,m,n,0,board,word))
                    return true;
            }
        }
        return false;
    }
};