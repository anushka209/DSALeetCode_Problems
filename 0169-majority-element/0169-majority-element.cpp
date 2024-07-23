class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n=nums.size();
        // map<int,int>mpp;
        // for(int i=0;i<n;i++)
        // {
        //     mpp[nums[i]]++;
        // }
        // for(auto it:mpp)
        // {
        //    if(it.second>(n/2))
        //     return it.first;
        // }
        // return -1;

        int count=0,ele;   //by moore voting algo
        for(int i=0;i<n;i++)
        {
            if(count==0)   //start with a new section
            {
                count=1;
                ele=nums[i];
            }
            else if(nums[i]==ele)
                count++;
            else
                count--;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
                cnt++;
            if(cnt>(n/2))
                return ele;
        }
        return -1;
    }
};