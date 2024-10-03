class Solution {
public:
    int findSmallestSubarray(vector<int>& nums,int p,int rem)
    {
        long long prefixSum=0;
        int minlen=nums.size();
        unordered_map<int,int>prefixMap;
        prefixMap[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            int targetRem=(prefixSum % p- rem + p) % p;
            if(prefixMap.find(targetRem)!=prefixMap.end())
            {
                minlen=min(minlen, i-prefixMap[targetRem]);
            }
            prefixMap[prefixSum % p]=i;
        }
        return minlen < nums.size() ? minlen : -1;
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