class Solution {
public:
    void find(int i,int n,vector<int>& candidates,int target,vector<int>& res,vector<vector<int>>& ans)
    {
        if(i==n)
        {
            if(target==0)
                ans.push_back(res);
            return;
        }
        if(candidates[i]<=target)
        {
            res.push_back(candidates[i]);
            find(i,n,candidates,target-candidates[i],res,ans);
            res.pop_back();
        }
        find(i+1,n,candidates,target,res,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>ans;
      vector<int>res;
      int n=candidates.size();
      find(0,n,candidates,target,res,ans);
      return ans;
    }
};