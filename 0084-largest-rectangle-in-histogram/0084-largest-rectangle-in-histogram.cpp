class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int>s;
   int n=heights.size();
   int l[n];
   int r[n];
   for (int i = 0; i < n; i++) // find left minimum
   {
     while (!s.empty() && heights[s.top()] >= heights[i])
       s.pop();
     if (!s.empty())
       l[i] = s.top() + 1;   //for boundary
     else
       l[i] = 0;
     s.push(i);
   }
   
      while(!s.empty())  s.pop();        //to empty the stack

      for(int i=n-1;i>=0;i--)    //find right minimum
      {
       while (!s.empty() && heights[s.top()] >= heights[i])
       s.pop();
     if (!s.empty())
       r[i] = s.top() -1;    //for boundary
     else
       r[i] = n-1;
     s.push(i);
      }

    int maxi=0;
    int ans;
      for(int i=0;i<n;i++)
      {
        ans=(r[i]-l[i]+1)*heights[i];
        maxi=max(maxi,ans);
      }
      return maxi;
    }
};