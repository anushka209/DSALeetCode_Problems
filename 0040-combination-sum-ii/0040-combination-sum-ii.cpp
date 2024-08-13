class Solution {
public:
    void find(int idx,vector<int>& candidates,int n,int target,vector<int> &res,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            res.push_back(candidates[i]);
            find(i+1,candidates,n,target-candidates[i],res,ans);
             res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        int n=candidates.size();
        find(0,candidates,n,target,res,ans);
        return ans;
    }
};