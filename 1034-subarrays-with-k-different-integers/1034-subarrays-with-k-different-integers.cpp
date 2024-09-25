class Solution {
public:
    int find_ans(vector<int>& nums, int k)
    {
      if(k<0)
        return 0;
      int n=nums.size();
      int l=0,r=0,count=0;
      map<int,int>mpp;
      while(r<n)
      {
        mpp[nums[r]]++;
        while(mpp.size()>k)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
                mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size()<=k)
        {
            int len=r-l+1;
            count=count+len;
        }
        r++;
      }
      return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find_ans(nums,k)-find_ans(nums,k-1);
    }
};