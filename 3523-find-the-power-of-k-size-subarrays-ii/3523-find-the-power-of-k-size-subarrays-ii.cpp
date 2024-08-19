class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        int count=1;
        for(int i=0;i<n;i++)
        {
           if(i && nums[i]==nums[i-1]+1)
             count++;
           else
             count=1;
           if(i+1>=k)
              res.push_back(count>=k ? nums[i] : -1);
        }
        return res;
    }
};