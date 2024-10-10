class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth=0;
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || nums[st.top()]>nums[i])    // create decreasing stack of indices
                st.push(i);
        }
        for(int i=n-1;i>=0;i--)     // traverse from end to find maximum width 
        {
            while(!st.empty() && nums[i]>=nums[st.top()])
            {
                maxWidth=max(maxWidth,i-st.top());
                st.pop();
            }
        }
        return maxWidth;
    }
};