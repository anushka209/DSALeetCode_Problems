class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<10)
                sum1+=nums[i];
            else
                sum2+=nums[i];
        }
        if(sum1>sum2 || sum2>sum1)
            return true;
        else
            return false;
    }
};