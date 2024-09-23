class Solution {
public:

    int findArea(vector<int> &h)
    {
    stack<int>s;
    int n=h.size();
   int l[n];
   int r[n];
   for (int i = 0; i < n; i++) // find left minimum
   {
     while (!s.empty() && h[s.top()] >= h[i])
       s.pop();
     if (!s.empty())
       l[i] = s.top();
     else
       l[i] = -1;
     s.push(i);
   }
   
      while(!s.empty())  s.pop();        //to empty the stack

      for(int i=n-1;i>=0;i--)    //find right minimum
      {
       while (!s.empty() && h[s.top()] >= h[i])
       s.pop();
     if (!s.empty())
       r[i] = s.top();
     else
       r[i] = n;
     s.push(i);
      }

    int width[n];
      for(int i=0;i<n;i++)
      {
        width[i]=(r[i]-l[i]-1);
      }

    int area;
    int MaxArea=0;

    for(int i=0;i<n;i++)
    {
        area=h[i]*width[i];
        MaxArea=max(MaxArea,area);
    }
    return MaxArea;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
     int r=matrix.size();
     int c=matrix[0].size();
     vector<int>h(c);
     for(int i=0;i<c;i++)
     {
        h[i]=(matrix[0][i]=='1') ? 1 : 0; 
     }

     int maxArea=findArea(h);

     for(int row=1;row<r;row++)
     {
        for(int col=0;col<c;col++)
        {
            if(matrix[row][col]=='0')
            {
                h[col]=0;
            }
            else
                h[col]+=1;
        }
   maxArea=max(maxArea,findArea(h));
     }
    return maxArea;       
    }
};