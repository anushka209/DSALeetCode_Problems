class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;    //we take Double ended queue to store in decreasing order and do operations from both end
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front()==i-k)       // to remove out of bound indexes 
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])     //if deque element<=array element then decreasing rule break so pop it
                dq.pop_back();
            dq.push_back(i);     //push in deque
            if(i>=k-1)          // if i goes at last index of k-1 and greater than it front is maximum element so return as ans
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};