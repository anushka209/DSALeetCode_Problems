class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++)
        {
            bool f=true;
            for(int j=i;j<(i+k-1);j++)
            {
                if(nums[j]!=nums[j+1]-1)
                {
                    f=false;
                    break;
                }
            }
            if(f) 
              res.push_back(nums[i+k-1]);
            else
               res.push_back(-1);
        }
        return res;
    }
};