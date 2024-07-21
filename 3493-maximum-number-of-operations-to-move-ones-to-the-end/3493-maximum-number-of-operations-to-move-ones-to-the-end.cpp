class Solution {
public:
    int maxOperations(string s) {
      int n=s.size();
      int count=0,ans=0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='0')         //in case of 0
        {
            ans+=count;
            while(i<n && s[i]!='1')   //for consecutive 0s
                i++;
        }
         count++;    //in case of 1
      }
      return ans;
    }
};