class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
    //    set<vector<int>>s;      //by hashing
    //    for(int i=0;i<n;i++)
    //    {
    //      set<int>st;
    //      for(int j=i+1;j<n;j++)
    //      {
    //         int third=-(nums[i]+nums[j]);
    //         if(st.find(third)!=st.end())
    //         {
    //             vector<int>temp={nums[i],nums[j],third};
    //             sort(temp.begin(),temp.end());
    //             s.insert(temp);
    //         }
    //         st.insert(nums[j]);
    //      }
    //    }
    //    vector<vector<int>>ans(s.begin(),s.end());
    //    return ans;

        vector<vector<int>>ans;         //2 pointer approach
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
        int j=i+1,k=n-1;
        while(j<k)
        {
            if(nums[i]+nums[j]+nums[k]==0){
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
            else if(nums[i]+nums[j]+nums[k]<0)
                j++;
            else if(nums[i]+nums[j]+nums[k]>0)
                k--;
        }
        }
        return ans;
    }
};