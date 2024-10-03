class Solution {
public:
    int findSmallestSubarray(vector<int>& nums,int p,int rem)
    {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int curr=0;
        mpp[0]=-1;
        int ans=n;
        for(int j=0;j<n;j++)
        {
            curr=(curr+nums[j])%p;
            int remain=(curr-rem + p)%p;
            if(mpp.find(remain)!=mpp.end())
            {
                ans=min(ans,j-mpp[remain]);
            }
            mpp[curr]=j;
        }
        return ans==n ? -1 : ans;
    }

    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int num:nums)
            sum+=num;
        int rem=sum % p;
        if(rem==0)
            return 0;
        return findSmallestSubarray(nums,p,rem);
    }
};