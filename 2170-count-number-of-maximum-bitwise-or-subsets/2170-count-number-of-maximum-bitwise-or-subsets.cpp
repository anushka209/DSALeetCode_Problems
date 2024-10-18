class Solution {
public:
    int countSubsets(int idx,vector<int>& nums,int currOR,int maxOR)
    {
        if(idx==nums.size())
        {
            if(currOR==maxOR)
                return 1;       // found 1 subset
            return 0;
        }
        // pick the current
        int takeCurr=countSubsets(idx+1,nums,currOR|nums[idx],maxOR);

        // not pick the current
        int notTakeCurr=countSubsets(idx+1,nums,currOR,maxOR);
        return takeCurr + notTakeCurr;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0;
        for(int num:nums)    // calculate maximum OR
            maxOR|=num;
        return countSubsets(0,nums,0,maxOR);
    }
};