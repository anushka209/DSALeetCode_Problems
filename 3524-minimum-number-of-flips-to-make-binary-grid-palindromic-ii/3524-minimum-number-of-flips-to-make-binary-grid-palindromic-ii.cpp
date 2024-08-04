class Solution {
public:
int minFlips(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for(int i=0;i<m/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            long x=grid[i][j];
            x+=grid[m-i-1][j];
            x+=grid[m-i-1][n-j-1];
            x+=grid[i][n-j-1];
            ans+=min(x,4-x);
        }
    }
    int c=0;       //pairs of ones
    int count=0;   //number of flips
    if(m%2==1)
    {
        for(int j=0;j<n/2;j++)
        {
            if(grid[m/2][j]!=grid[m/2][n-j-1])
            {
                ans++;
                count++;
            }
            if((grid[m/2][j]==grid[m/2][n-j-1]) && grid[m/2][j]==1)
                c++;
        }
    }
    if(n%2==1)
    {
        for(int j=0;j<m/2;j++)
        {
            if(grid[j][n/2]!=grid[m-j-1][n/2])
            {
                ans++;
                count++;
            }
            if((grid[j][n/2]==grid[m-j-1][n/2])&&grid[j][n/2]==1)
                c++;
        }
    }
    if((c%2==1) && (count==0)) ans+=2;
    if((m%2==1) &&(n%2==1) && (grid[m/2][n/2]==1))
        ans++;
    return ans;
    }
};



