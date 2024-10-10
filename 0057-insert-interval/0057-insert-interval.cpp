class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
       vector<vector<int>>ans;
       int n=arr.size();
       int i=0;
       while(i<n && arr[i][1] < newInterval[0])     //for left
       {
         ans.push_back(arr[i]);
         i++;
       }
       while(i<n && arr[i][0] <= newInterval[1])        //for overlapping
       {
          newInterval[0]=min(arr[i][0],newInterval[0]);
          newInterval[1]=max(arr[i][1],newInterval[1]);
          i++;
       }
       ans.push_back(newInterval);
       while(i<n)           //for right
       {
           ans.push_back(arr[i]);
           i++;
       }
       return ans;
    }
};