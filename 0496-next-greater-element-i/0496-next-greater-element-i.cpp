class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();
      vector<int>ans(n,-1);
      stack<int>st;
      map<int,int>mpp;
      for(int num:nums2)
      {
         while(!st.empty() && st.top()<num)
         {
            mpp[st.top()]=num;
            st.pop();
         }
         st.push(num);
      }
      for(int i=0;i<n;i++)
      {
        if(mpp[nums1[i]])
            ans[i]=mpp[nums1[i]];
      }
      return ans;
    }
};