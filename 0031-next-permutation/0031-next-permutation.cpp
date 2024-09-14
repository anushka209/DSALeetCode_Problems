class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      //  next_permutation(nums.begin(),nums.end());
      
      int n=nums.size();
      if(n<2) return;
      int idx=-1;
      for(int i=n-2;i>=0;i--)      //find the break point
      {
        if(nums[i]<nums[i+1])
        {
            idx=i;
            break;
        }
      }
      if(idx==-1){
        reverse(nums.begin(),nums.end());
            return;
      }
      for(int i=n-1;i>idx;i--)       // Find the next greater element and swap it with arr[ind]:
      {
        if(nums[i]>nums[idx])
        {
            swap(nums[i],nums[idx]);
            break;
        }
      }
      reverse(nums.begin()+idx+1,nums.end());
    }
};