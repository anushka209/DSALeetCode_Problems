class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        int total=n*m;

        int srow=0;
        int scol=0;
        int erow=n-1;
        int ecol=m-1;

        while(count<total)
        {
            //print starting row
            for(int idx=scol;count<total && idx<=ecol;idx++)
            {
                ans.push_back(matrix[srow][idx]);
                count++;
            }
            srow++;

             //print ending col
            for(int idx=srow;count<total && idx<=erow;idx++)
            {
                ans.push_back(matrix[idx][ecol]);
                count++;
            }
            ecol--;

             //print ending row
            for(int idx=ecol;count<total && idx>=scol;idx--)
            {
                ans.push_back(matrix[erow][idx]);
                count++;
            }
            erow--;

             //print starting col
            for(int idx=erow;count<total && idx>=srow;idx--)
            {
                ans.push_back(matrix[idx][scol]);
                count++;
            }
            scol++;
        }
      return ans;
    }  
};