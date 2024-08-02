class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    //    int maxi=INT_MIN;
    //    int ans=0;
    //    for(int i=0;i<nums.size();i++)
    //    {
    //       if(nums[i]>maxi)
    //       {
    //         maxi=nums[i];
    //         ans=i;
    //       }
    //    }
    //    return ans;

     int n=nums.size();
     if(n==1) return 0;
     if(nums[0]>nums[1]) return 0;
     if(nums[n-1]>nums[n-2]) return n-1;
     int s=1,e=n-2;
     while(s<=e)
     {
        int mid=s+(e-s)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
        if(nums[mid]>nums[mid-1])    // we are in left
            s=mid+1;
        else
            e=mid-1;       // we are in right
     }
     return -1;
    }
};

  