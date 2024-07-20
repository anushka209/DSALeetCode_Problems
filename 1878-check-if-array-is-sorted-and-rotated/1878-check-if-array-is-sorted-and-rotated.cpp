class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size(); 
        for(int i=1;i<n;i++)              // Check if the array is non-decreasing
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[n-1]>nums[0])            // Check if the last element is greater than the first element
        count++;
        return count<=1;                   // If the count of violations is less than or equal to 1, return true
    }
};