class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int count=0,maxi=1;
        int last=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==last){
                count++;
                last=nums[i];
            }
            else if(nums[i]!=last){
                count=1;
                last=nums[i];
            }
        maxi=max(maxi,count);
        }
        return maxi;
    }
};