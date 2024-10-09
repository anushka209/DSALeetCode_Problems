class Solution {
public:
    bool canJump(vector<int>& nums) {
     int n=nums.size();
     int maxIdx=0;         // store maximum index that can be reached
     for(int i=0;i<n;i++)
     {
        if(i>maxIdx)  return false;
        maxIdx=max(maxIdx,i+nums[i]);   // index + value becoz to get max index we can reached
     }
     return true;
    }
};