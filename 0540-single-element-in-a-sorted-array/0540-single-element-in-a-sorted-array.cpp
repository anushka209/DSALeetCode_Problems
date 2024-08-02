class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // int ans=0;         //by xor
        // for(int i=0;i<n;i++)
        // {
        //     ans=ans^nums[i];
        // }
        // return ans;
       
        if(n==1)  return nums[0];   //by binary search
        if(nums[0]!=nums[1])  return nums[0];
        if(nums[n-1]!=nums[n-2])  return nums[n-1];

        int s=1,e=n-2;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return  nums[mid];
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])) //for left half elimination
                s=mid+1;
            else                   //for right half elimination
                e=mid-1;
        }
        return -1;
	}
};