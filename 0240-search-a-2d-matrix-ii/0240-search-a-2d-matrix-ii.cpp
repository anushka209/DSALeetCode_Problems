class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

      int ridx=0,cidx=col-1;
      while(ridx<row && cidx>=0)
      {
        if(matrix[ridx][cidx]==target)
            return true;
        else if(matrix[ridx][cidx]<target)
            ridx++;
        else
            cidx--;
      }
      return false;
    }
};