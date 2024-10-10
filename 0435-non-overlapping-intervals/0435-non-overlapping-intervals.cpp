class Solution {
public:
    static bool comp(vector<int>& v1,vector<int>& v2)
    {
        return v1[1]<v2[1];   // sort according to endtime
    }

    int eraseOverlapIntervals(vector<vector<int>>& arr) {
      int n=arr.size();
      sort(arr.begin(),arr.end(),comp);
      int count=1;
      int lastIns=arr[0][1];
      for(int i=1;i<n;i++)
      {
        if(arr[i][0]>=lastIns)
        {
            count++;
            lastIns=arr[i][1];
        }
      }
      return n-count;
    }
};