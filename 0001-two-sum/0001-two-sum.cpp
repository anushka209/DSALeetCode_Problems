class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //   vector <int> v;
    //   for(int i=0;i<nums.size()-1;i++)      //brute
    //   {
    //       for(int j=i+1;j<nums.size();j++)
    //       {
    //           if(nums[i]+nums[j]==target)
    //           {
    //              v.push_back(i);
    //              v.push_back(j);
    //           }
    //       }
    //   }  
    //   return v;

        vector<int>v;
        unordered_map<int,int>mpp;    //value & index
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int rem=target-nums[i];
            if(mpp.find(rem)!=mpp.end())
            {
                v={i,mpp[rem]};
                break;
            }
            mpp[nums[i]]=i;
        }
            return v;

        // vector<int>v;              //2 pointer approach
        // int n=nums.size();
        // int l=0,r=n-1;
        // sort(nums.begin(),nums.end());
        // while(l<r)
        // {
        //     if(nums[l]+nums[r]==target)
        //     {
        //         v.push_back(l);
        //         v.push_back(r);
        //     }
        //     else if(nums[l]+nums[r]<target)
        //         l++;
        //     else
        //         r--;
        // }
        // return v;
    }
};