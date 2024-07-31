class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       double maxi=INT_MIN;
    //    for(int i=0;i<n;i++)
    //    {
    //       long prod=1;
    //     for(int j=i;j<n;j++)
    //     {
    //         prod=prod*nums[j];
    //         maxi=max(maxi,(int)prod);
    //     }
    //    } 
    //    return maxi;

       double pre=1,suff=1;
       for(int i=0;i<n;i++)
       {
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre=pre*nums[i];
        suff=suff*nums[n-i-1];
        maxi=max(maxi,max(pre,suff));
       }
       return maxi;
    }
};