class Solution {
public:
    int findMin(vector<int>& nums) {
        // int mini=INT_MAX;                //brute approach
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]<mini)
        //         mini=nums[i];
        // }
        // return mini;

        int s=0,e=nums.size()-1;
        int ans=INT_MAX;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[s]<=nums[e])     //already sorted
            {
                ans=min(ans,nums[s]);
                break;
            }
            if(nums[s]<=nums[mid])  //left half sorted
            {
                ans=min(ans,nums[s]);
                s=mid+1;
            }
            else                  //right half sorted
            {
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};