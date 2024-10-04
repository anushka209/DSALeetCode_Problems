class Solution {
public:
    void find(int idx,int n,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans)
    {
        ans.push_back(res);     //no need of base case becoz of loop
        for(int i=idx;i<n;i++)
        {
            if(i!=idx && nums[i]==nums[i-1]) continue;         //duplicates--so not pick
            res.push_back(nums[i]);
            find(i+1,n,nums,res,ans);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>res;
      int n=nums.size();
      sort(nums.begin(),nums.end());
      find(0,n,nums,res,ans);
      return ans;
    }
};