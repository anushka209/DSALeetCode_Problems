class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vec;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int l=vec.size();
        int target=vec[l/2];
        int result=0;

        for(int &nums:vec)
        {
            if(target%x != nums%x)   // we cannot make uni-value grid
                return -1;
            result+= abs(target-nums)/x;
        }
        return result;
    }
};