class Solution {
public:
    int maxi(vector<int>& nums)
    {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,nums[i]);
        }
        return ans;
    }

    int sumfunc(vector<int>& nums,int mid)
    {
       int n=nums.size();
       int ans=0;
       for(int i=0;i<n;i++)
       {
          ans+=(nums[i]/mid)+((nums[i]%mid)!=0);
       }
       return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
       int n=nums.size();
       int s=1,e=maxi(nums);
       int ans=e;
       if(n>threshold)  return -1;
       while(s<=e)
       {
        int mid=s+(e-s)/2;
        int val=sumfunc(nums,mid);
        if(val<=threshold)
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
       }
       return ans;
    }
};