class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int num=INT_MAX;
            int index=-1;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<num)    //find minimum in its row 
                {
                    num=matrix[i][j];
                    index=j;
                }
            }
            bool flag=true;
            for(int row=0;row<m;row++)     //find maximum in its column
            {
                if(matrix[row][index]>num)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                ans.push_back(num);
        }
        return ans;
    }
};