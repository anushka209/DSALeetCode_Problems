class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int>pq;
      for(int i=0;i<nums.size();i++)
        pq.push(nums[i]);
      int x=k-1;
      while(x>0)
      {
        pq.pop();
        x--;
      }
      return pq.top();
    }
};