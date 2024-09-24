class Solution {
public:
    int find_subarray(vector<int>& nums,int goal)
    {
        if(goal<0)    //edge case 
            return 0;
        int n=nums.size();
        int l=0,r=0,count=0,sum=0;
        while(r<n)
        {
            sum=sum+nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            int len=r-l+1;
            count=count+len;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find_subarray(nums,goal)-find_subarray(nums,goal-1);
    }
};