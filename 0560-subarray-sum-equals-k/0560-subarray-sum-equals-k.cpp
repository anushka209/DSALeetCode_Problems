class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int count=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         sum+=nums[j];
        //         if(sum==k)
        //             count++;
        //     }
        // }
        // return count;

        map<int,int>mpp;    //preSum & count        //using map approach
        int count=0,preSum=0;
        mpp[0]=1;       //most imp. case
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];             // add current element to prefix Sum:
            int remove=preSum-k;         // Calculate x-k:
            count+=mpp[remove];       // Add the number of subarrays to be removed:
            mpp[preSum]+=1;           // Update the count of prefix sum in the map.
        }
        return count;
    }
};