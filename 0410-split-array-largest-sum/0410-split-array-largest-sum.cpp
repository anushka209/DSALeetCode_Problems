class Solution {
public:

bool possible(vector<int> nums, int k,int mid)
{
    int count=1,psum=0;
        int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(psum+nums[i]<=mid)
        {
            psum+=nums[i];
        }
        else
        {
            count++;
            if(count>k || nums[i]>mid)
            {
                return false;
            }
            psum=nums[i];
        }
    }
    return true;
}

    int splitArray(vector<int>& nums, int k) {
    int s=0,sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
    }
   int  e=sum,ans=-1;
   while(s<=e)
   {
       int mid=s+(e-s)/2;
       if(possible(nums, k,mid))
       {
           ans=mid;
           e=mid-1;
       }
       else
       s=mid+1;
   }
   return ans;  
    }
};