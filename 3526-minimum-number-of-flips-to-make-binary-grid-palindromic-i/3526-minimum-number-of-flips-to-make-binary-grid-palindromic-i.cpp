class Solution {
public:
    int minFlips(vector<vector<int>>& grid)
    {
      int m=grid.size();
      int n=grid[0].size();
      int row=0,col=0;
      for(int i=0;i<m;i++)    //for rows flip
      {
        for(int j=0;j<n/2;j++)
        {
            if(grid[i][j]!=grid[i][n-j-1])
                row++;
        }
      } 
       for(int i=0;i<n;i++)    //for col flip
      {
        for(int j=0;j<m/2;j++)
        {
            if(grid[j][i]!=grid[m-j-1][i])
                col++;
        }
      }   
      return min(row,col); 
    }
};


