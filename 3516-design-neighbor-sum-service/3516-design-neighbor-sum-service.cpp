class neighborSum {
public:
    int n;
    vector<vector<int>>arr;
    map<int,pair<int,int>>mpp;
    neighborSum(vector<vector<int>>& grid){
        n = grid.size();
       arr=grid;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            mpp[grid[i][j]]={i,j};
        }
       }
    }

    int adjacentSum(int value) {
       int i=mpp[value].first;
       int j=mpp[value].second;
       int sum=0;
       if(i-1>=0) sum+=arr[i-1][j];
       if(j-1>=0) sum+=arr[i][j-1];
       if(i+1<n) sum+=arr[i+1][j];
       if(j+1<n) sum+=arr[i][j+1];
       return sum;
    }

    int diagonalSum(int value) {
       int i=mpp[value].first;
       int j=mpp[value].second;
       int sum=0;
       if((i-1>=0) &&(j-1>=0)) sum+=arr[i-1][j-1];
       if((i-1>=0) &&(j+1<n)) sum+=arr[i-1][j+1];
       if((j+1<n) &&(i+1<n)) sum+=arr[i+1][j+1];
       if((i+1<n) &&(j-1>=0)) sum+=arr[i+1][j-1];
       return sum;
    }
};

