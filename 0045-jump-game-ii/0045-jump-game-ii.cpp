class Solution {
public:
    // int find(vector<int>& nums,int idx,int jumps)
    // {
    //     int n=nums.size();             // gives TLE solve using dp
    //     if(idx>=n-1)  return jumps;
    //     int mini=INT_MAX;
    //     for(int i=1;i<nums[idx];i++){
    //         mini=min(mini,find(nums,idx+i,jumps+1));
    //     }
    //     return mini;
    // }

    int jump(vector<int>& nums) {
        // return find(nums,0,0);
                                            // range concept
      int n=nums.size();
      int l=0,r=0,jumps=0;
      while(r < n-1)
      {
        int farthest=0;
        for(int i=l;i<=r;i++)
        {
            farthest=max(farthest,i+nums[i]);
        }
        l=r+1;
        r=farthest;
        jumps++;
      }
      return jumps;
    }
};