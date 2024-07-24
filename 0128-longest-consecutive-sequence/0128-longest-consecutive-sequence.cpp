class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxi=1;

        // int last=INT_MIN;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]-1==last){
        //         count++;
        //         last=nums[i];
        //     }
        //     else if(nums[i]!=last){
        //         count=1;
        //         last=nums[i];
        //     }
        // maxi=max(maxi,count);
        // }
        // return maxi;

        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        for(auto it:s)
        {
            if(s.find(it-1)==s.end())    //it is starting element
            {
                int count=1;
                int x=it;
                while(s.find(x+1)!=s.end())
                {
                    count++;
                    x=x+1;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};