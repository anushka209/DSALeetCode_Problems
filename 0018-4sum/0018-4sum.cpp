class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        // set<vector<int>>s;
        // for(int i=0;i<n;i++)              // by taking set
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         set<long long>st;
        //         for(int k=j+1;k<n;k++)
        //         {
        //             long long sum=nums[i]+nums[j];
        //             sum+=nums[k];
        //             long long fourth=target-sum;
        //             if(st.find(fourth)!=st.end())
        //             {
        //                 vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
        //                 sort(temp.begin(),temp.end());
        //                 s.insert(temp);
        //             }
        //            st.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>>ans(s.begin(),s.end());
        // return ans;
          
        vector<vector<int>>ans;            // kind of 2 pointer approach
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])  continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target)
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};