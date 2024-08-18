class Solution {
public:

int findmax(vector<vector<int>> &mat,int row,int col,int mid)
{
   int idx=-1,max_val=-1;
   for(int i=0;i<row;i++)
   {
     if(mat[i][mid]>max_val)
     {
        max_val=mat[i][mid];
        idx=i;
     }
   }
   return idx;
}

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int row=mat.size();
    int col=mat[0].size();
    int s=0,e=col-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int max_idx=findmax(mat,row,col,mid);
        int left = mid-1>=0 ? mat[max_idx][mid-1] : -1;
        int right = mid+1<col ? mat[max_idx][mid+1] : -1;
        if(mat[max_idx][mid] > left && mat[max_idx][mid]>right)
        {
            return {max_idx,mid};
        }
        else if(mat[max_idx][mid]<left)
            e=mid-1;
        else
            s=mid+1;
    }
    return {-1,-1};
    }
};