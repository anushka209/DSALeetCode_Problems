class Solution {
public:
    bool isSmallpairs(vector<int>& nums, int k,int mid)
    {
        int count=0,l=0;
        for(int r=0;r<nums.size();r++)
        {
            while(nums[r]-nums[l]>mid)
                l++;
            count+=r-l;
        }
        return (count>=k);
    }

    int smallestDistancePair(vector<int>& nums, int k)
    {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int left=0,right=nums[n-1]-nums[0];
       while(left < right)
        {
            int mid=(left+right)/2;
            if(isSmallpairs(nums,k,mid))
                right=mid;
            else 
                left=mid+1;
        }
     return left;
    }
};