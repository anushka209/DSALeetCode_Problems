class Solution {
    private:
    // void solve(vector<int>& nums,vector<int>output,int index,vector<vector<int>>& ans)
    // {
    //     if(index>=nums.size())       //base case
    //     {
    //         ans.push_back(output);
    //         return;
    //     }
    //     solve(nums,output,index+1,ans);      //exclude

    //     int ele=nums[index];         //include
    //     output.push_back(ele);
    //     solve(nums,output,index+1,ans);
    // }

    void find(int i,int n,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans)
    {
        if(i>=n)
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        find(i+1,n,nums,res,ans);

        res.pop_back();             // backtracking
        find(i+1,n,nums,res,ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        // vector<int>output;
        // int index=0;
        // solve(nums,output,index,ans);
        // return ans;

        int n=nums.size();

        // int subset=1<<n;
        // for(int i=0;i<subset;i++)
        // {
        //     vector<int>s;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i & (1<<j))
        //             s.push_back(nums[j]);
        //     }
        //     ans.push_back(s);
        // } 
        // return ans;

       find(0,n,nums,res,ans);
       return ans;
    }  
};