class Solution {
public:
    long long minimumSteps(string s) {
      int n=s.size();
      int black=0;
      long long ans=0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='0')
            ans+=black;
        else
            black++;
      }
      return ans;
    }
};