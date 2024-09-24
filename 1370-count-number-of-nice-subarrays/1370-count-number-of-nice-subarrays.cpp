class Solution {
public:
    int find_sub(vector<int>& nums,int k)
    {
        if(k<0)
            return 0;
        int n=nums.size();
        int l=0,r=0,count=0,sum=0;
        while(r<n)
        {
            sum=sum+(nums[r]%2);
            while(sum>k)
            {
                sum=sum-(nums[l]%2);
                l++;
            }
            int len=r-l+1;
            count=count+len;    //to include value as combined and also single into the answer
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return find_sub(nums,k)-find_sub(nums,k-1);
    }
};