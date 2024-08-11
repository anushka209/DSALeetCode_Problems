class Solution {
public:
     void dfs(vector<vector<int>> &matrix,int r,int c)
     {
        if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size() || matrix[r][c]==1)
            return;
        matrix[r][c]=1;     //mark visited

        //for all 4 directions
        dfs(matrix,r+1,c);
        dfs(matrix,r-1,c);
        dfs(matrix,r,c+1);
        dfs(matrix,r,c-1);
     }

    int regionsBySlashes(vector<string>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     int regions=0;
     vector<vector<int>> matrix(n*3,vector<int>(m*3,0));
     
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='/')
            {
                matrix[i*3][j*3+2]=1;
                matrix[i*3+1][j*3+1]=1;
                matrix[i*3+2][j*3]=1;
            }
            else if(grid[i][j]=='\\')
            {
                matrix[i*3][j*3]=1;
                matrix[i*3+1][j*3+1]=1;
                matrix[i*3+2][j*3+2]=1;
            }
        }
     }
        // apply concept of number of islands
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)      // call dfs
                {
                    dfs(matrix,i,j);
                    regions++;
                }
            }
        }
        return regions;
    }
};